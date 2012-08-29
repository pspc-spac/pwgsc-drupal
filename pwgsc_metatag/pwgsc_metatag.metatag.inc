<?php
/**
 * @file
 * Meta tag definitions for the PWGSC Meta Tags module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function pwgsc_metatag_metatag_config_default_alter(array &$configs) {
  global $language;

  // Get the department-wide prefix for any meta tags.
  $prefix = pwgsc_metatag_prefix_get();

  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(

          // By default, have the value unset so that users will fail ITSB's
          // Web Planning and Standards Services validation testing unless they
          // set this explicitly.  Setting a default here would be bad because
          // (1) it would pass validation, and (2) the address would be
          // incorrect.
          $prefix . '.contact.email' => array('value' => ''),

        );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 * Dublin Core Elements taken from http://purl.org/dc/elements/1.1/.
 */
function pwgsc_metatag_metatag_info() {

  // Get the department-wide prefix for any meta tags.
  $prefix = pwgsc_metatag_prefix_get();

  // Define the metatag groups.
  $info['groups']['pwgsc'] = array(
    'label' => t('PWGSC'),
    'description' => t('Metadata tags specific to (the department of) Public Works and Government Services Canada'),
    'form' => array(
      '#weight' => 96,
    ),
  );

  // Define all of the tags within all of the groups.
  $info['tags'][$prefix . '.contact.email'] = array(
    'label' => t('Site e-mail address'),
    'description' => t('E-mail address for the PWGSC Web site'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'pwgsc',
    'element' => array(
      '#type' => 'term',
      '#theme' => 'wetkit_metatag',
    ),
  );

  return $info;
}

/**
 * Returns the deparment-wide prefix used for PWGSC's meta tags.
 *
 * @return
 *   The prefix.
 */
function pwgsc_metatag_prefix_get() {
  return 'pwgsc';
}

