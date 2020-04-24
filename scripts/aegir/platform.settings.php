<?php # platform.settings.php

/*
 * Define CIVICRM_L10N_BASEDIR environmental variable for l10n files
 * see: https://lab.civicrm.org/dev/translation/-/issues/30
 * PLATFORM_DIR are be replaced at install time
 * sed -i "s/PLATFORM_DIR/$(basename $PWD)/g" scripts/aegir/platform.settings.php
 */
define('CIVICRM_L10N_BASEDIR', '/var/aegir/platforms/PLATFORM_DIR/web/profiles/civicrmprofile/translations/contrib/civicrm/l10n');
