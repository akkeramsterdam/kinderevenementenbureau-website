<?php
/**
 * @file
 * custom_image_gallery.features.inc
 */

/**
 * Implementation of hook_views_api().
 */
function custom_image_gallery_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function custom_image_gallery_node_info() {
  $items = array(
    'afbeelding' => array(
      'name' => t('Afbeelding'),
      'base' => 'node_content',
      'description' => t('Voeg een afbeelding toe aan een foto album.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'foto_album' => array(
      'name' => t('Foto album'),
      'base' => 'node_content',
      'description' => t('Maak een nieuw foto-album aan en voeg via de "voeg foto toe" nieuwe afbeeldingen toe.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
