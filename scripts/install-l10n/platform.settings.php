<?php # platform.settings.php

/*
 * Define CIVICRM_L10N_BASEDIR environmental variable for l10n files
 * see: https://lab.civicrm.org/dev/translation/-/issues/30
 * PLATFORM_DIR will be replaced during install
 * sed -i "s/PLATFORM_DIR/$(basename $PWD)/g" scripts/aegir/platform.settings.php
 */
define('CIVICRM_L10N_BASEDIR', '/var/aegir/platforms/PLATFORM_DIR/vendor/civicrm/civicrm-core/l10n');
