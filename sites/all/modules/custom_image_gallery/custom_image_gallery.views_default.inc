<?php
/**
 * @file
 * custom_image_gallery.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function custom_image_gallery_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'albums_overzicht';
  $view->description = 'Albums overzicht';
  $view->tag = 'Albums overzicht';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Foto albums';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Terugzetten';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Veld: Inhoud: Album cover */
  $handler->display->display_options['fields']['field_album_cover']['id'] = 'field_album_cover';
  $handler->display->display_options['fields']['field_album_cover']['table'] = 'field_data_field_album_cover';
  $handler->display->display_options['fields']['field_album_cover']['field'] = 'field_album_cover';
  $handler->display->display_options['fields']['field_album_cover']['label'] = '';
  $handler->display->display_options['fields']['field_album_cover']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_album_cover']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_album_cover']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_album_cover']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_album_cover']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_album_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_album_cover']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_album_cover']['field_api_classes'] = 0;
  /* Sort criterion: Inhoud: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'foto_album' => 'foto_album',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  /* Display: Pagina */
  $handler = $view->new_display('page', 'Pagina', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'foto-albums';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Foto albums';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  /* Display: Blok */
  $handler = $view->new_display('block', 'Blok', 'block_1');
  $translatables['albums_overzicht'] = array(
    t('Defaults'),
    t('Foto albums'),
    t('more'),
    t('Apply'),
    t('Terugzetten'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Pagina'),
    t('Blok'),
  );
  $export['albums_overzicht'] = $view;

  $view = new view;
  $view->name = 'foto_s';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'foto\'s';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Testblock';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Terugzetten';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Veld: Inhoud: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'colorbox_node_style' => 'thumbnail',
    'colorbox_image_style' => 'large',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Sort criterion: Inhoud: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Inhoud: Foto album (field_foto_album) */
  $handler->display->display_options['arguments']['field_foto_album_nid']['id'] = 'field_foto_album_nid';
  $handler->display->display_options['arguments']['field_foto_album_nid']['table'] = 'field_data_field_foto_album';
  $handler->display->display_options['arguments']['field_foto_album_nid']['field'] = 'field_foto_album_nid';
  $handler->display->display_options['arguments']['field_foto_album_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_foto_album_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_foto_album_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_foto_album_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_foto_album_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_foto_album_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_foto_album_nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_foto_album_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_foto_album_nid']['validate_options']['types'] = array(
    'foto_album' => 'foto_album',
  );
  $handler->display->display_options['arguments']['field_foto_album_nid']['validate_options']['access'] = '1';
  $handler->display->display_options['arguments']['field_foto_album_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_foto_album_nid']['not'] = 0;
  /* Filter criterion: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'afbeelding' => 'afbeelding',
  );

  /* Display: Entity content */
  $handler = $view->new_display('entity_view', 'Entity content', 'entity_view_1');
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'foto_album',
  );
  $translatables['foto_s'] = array(
    t('Master'),
    t('Testblock'),
    t('more'),
    t('Apply'),
    t('Terugzetten'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Alle'),
    t('Entity content'),
  );
  $export['foto_s'] = $view;

  return $export;
}
