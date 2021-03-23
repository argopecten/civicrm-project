#!/usr/bin/env bash
# download & unzip l10n tar file

CRM_VERSION=$1
echo "CRM version is: $CRM_VERSION"

wget -O /tmp/l10n.tar.gz "https://download.civicrm.org/civicrm-$CRM_VERSION-l10n.tar.gz"
tar -xzf /tmp/l10n.tar.gz -C /tmp

# copy language files
mkdir -p vendor/civicrm/civicrm-core/l10n
cp -R /tmp/civicrm/l10n/hu_HU/ vendor/civicrm/civicrm-core/l10n

# copy SQL files
cp /tmp/civicrm/sql/*.hu_HU.mysql vendor/civicrm/civicrm-core/sql/

# l10n settings file: settings.default.json
# quick & dirty, needed until not included in official l10n repo
# https://lab.civicrm.org/dev/translation/-/merge_requests/3
cp -rl scripts/install-l10n/settings.default.json vendor/civicrm/civicrm-core/l10n/hu_HU

# define CIVICRM_L10N_BASEDIR environmental variable as platform settings in Aegir
cp -rl scripts/install-l10n/platform.settings.php web/sites/all/
sed -i "s/PLATFORM_DIR/$(basename $PWD)/g" web/sites/all/platform.settings.php

# clean up
rm -rf /tmp/l10n.tar.gz /tmp/civicrm
