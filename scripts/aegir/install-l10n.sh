#!/usr/bin/env bash

# download & unzp l10n tar file
wget -O /tmp/l10n.tar.gz https://download.civicrm.org/civicrm-5.24.6-l10n.tar.gz
tar -xzf /tmp/l10n.tar.gz -C /tmp

# copy language file
mkdir -p web/profiles/civicrmprofile/translations/contrib/civicrm/l10n
cp -r /tmp/civicrm/l10n/hu_HU/ web/profiles/civicrmprofile/translations/contrib/civicrm/l10n

# l10n setting file: settings.default.json
# quick & dirty, should be in official l10n repo
cp -rl scripts/aegir/settings.default.json web/profiles/civicrmprofile/translations/contrib/civicrm/l10n/hu_HU

# copy SQL file
cp /tmp/civicrm/sql/*.hu_HU.mysql web/sites/all/modules/contrib/civicrm/sql/

# define CIVICRM_L10N_BASEDIR environmental variable in Aegir
cp -rl scripts/aegir/platform.settings.php web/sites/all
sed -i "s/PLATFORM_DIR/$(basename $PWD)/g" web/sites/all/platform.settings.php

# clean up
rm -rf /tmp/l10n.tar.gz /tmp/civicrm
