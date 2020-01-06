<?php

  /**
   * 2 functions to implement drush_hook_post_COMMAND().
   *
   *   - drush_crmproject_post_provision_install()
   *   - drush_crmproject_post_provision_verify()
   *
   * CRM module is not yet enabled  when .install file runs,
   * so CRM permissions will be granted here, via drush hook of
   * drush_hook_post_COMMAND(), allowing Aegir to run extra code after install tasks
   */
  function drush_crmproject_post_provision_install() {
    // drush_log('crmproject d():' . print_r(d(), 1), 'debug');
    $context = d()->context_type;
    if ($context === "platform") {
      // drush_log('context_type: ' . $context, 'debug');
      // do nothing
    } elseif ($context === "site") {
      // revoke CRM permissions from the site admin
      _drush_crmproject_revoke_siteadmin_permissions();
      // grant CRM admin permissions to CRM admin
      _drush_crmproject_grant_crmadmin_permissions();
      // grant CRM permissions to CRM superuser
      _drush_crmproject_grant_superuser_permissions();
    } else {
      // something is wrong...
      drush_log('wrong context at drush_crmproject_post_provision_verify: ' . $context, 'warning');
    }
  }

  function drush_crmproject_post_provision_verify() {
    // drush_log('crmproject d():' . print_r(d(), 1), 'debug');
    $context = d()->context_type;
    if ($context === "platform") {
      // drush_log('context_type: ' . $context, 'debug');
      // do nothing
    } elseif ($context === "site") {
      // revoke CRM permissions from the site admin
      _drush_crmproject_revoke_siteadmin_permissions();
      // grant CRM admin permissions to CRM admin
      _drush_crmproject_grant_crmadmin_permissions();
      // grant CRM permissions to CRM superuser
      _drush_crmproject_grant_superuser_permissions();
    } else {
      // something is wrong...
      drush_log('wrong context at drush_crmproject_post_provision_verify: ' . $context, 'warning');
    }
  }

  // grant CRM admin permissions for CRM admin
  function _drush_crmproject_grant_crmadmin_permissions() {
    drush_invoke('role-add-perm',
      array(
       'crm admin',
       array(
         'administer CiviCRM',
         'access all custom data',
       )
      )
    );
  }

  // grant CRM permissions to CRM superuser
  function _drush_crmproject_grant_superuser_permissions();
    drush_invoke('role-add-perm',
      array(
       'super user',
       array(
         'access all custom data',
       )
      )
    );
  }

  // revoke all CRM permissions from site admin
  function _drush_crmproject_revoke_siteadmin_permissions() {
    $crm_permissions = array_keys(module_invoke("civicrm", 'permission'));
    // drush_log('crm_permissions:' . print_r($crm_permissions, 1), 'debug');
    drush_invoke('role-remove-perm',
      array(
        'site admin',
        $crm_permissions,
      )
    );
  }

  // revoke all permissions and assign new pers to $role
  function _drush_crmproject_update_permissions($roles, $new_perms) {

    $all_permissions=array_keys(module_invoke_all('permission'));
    foreach ($roles as $name){
      $rid=user_role_load_by_name($name)->rid;
      user_role_revoke_permissions($rid, $all_permission);
    }

    $roles = user_roles(TRUE, $permission);
      foreach ($roles as $rid => $role) {
      }
      user_role_grant_permissions($siteadmin_role->rid, array_keys(module_invoke_all('permission')));

    $crm_permissions = array_keys(module_invoke("civicrm", 'permission'));
    // drush_log('crm_permissions:' . print_r($crm_permissions, 1), 'debug');
    drush_invoke('role-remove-perm',
      array(
        'site admin',
        $crm_permissions,
      )
    );
  }

?>
