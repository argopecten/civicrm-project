<?php

/**
 * @file
 * Contains \CiviCRMProject\composer\CiviCRMSetup.
 */

namespace CiviCRMProject\composer;

class CiviCRMSetup {

  /**
   * Change CiviCRM permissions of admin roles:
   * - remove all CiviCRM permissions from site administrator role
   * - grant all CiviCRM permissions to CRM administrator role
   */
  public static function changeCrmPermissions() {

    // revoke CRM permissions from site administrator
    $sieadmin_role = user_role_load_by_name('site admin');
    user_role_change_permissions($crmadmin_role->rid,
       array(
         'add contacts' => FALSE,
         'view all contacts' => FALSE,
         'edit all contacts' => FALSE,
         'view my contact ' => FALSE,
         'edit my contact' => FALSE,
         'delete contacts' => FALSE,
         'access deleted contacts' => FALSE,
         'import contacts' => FALSE,
         'import SQL datasource' => FALSE,
         'edit groups' => FALSE,
         'administer CiviCRM' => FALSE,
         'skip IDS check' => FALSE,
         'access uploaded files' => FALSE,
         'profile listings and forms' => FALSE,
         'profile listings' => FALSE,
         'profile create' => FALSE,
         'profile edit' => FALSE,
        )
    );

    // grant CRM admin permissions to CRM administrator
    $crmadmin_role = user_role_load_by_name('crm admin');
    user_role_change_permissions($crmadmin_role->rid,
       array(
         'administer CiviCRM' => TRUE,
         'access all custom data' => TRUE,
         'access CiviCRM backend and API' => TRUE,
        )
    );

  }

}
