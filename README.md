# Composer template for Drupal projects

CiviCRM platform with Drupal 7 on Aegir 3, with composer
This project template provides [CiviCRM](https://civicrm.org) platform with [Drupal 7](https://www.drupal.org/) on [Aegir 3](https://www.aegirproject.org), using [Composer](https://getcomposer.org/).

## Usage

First you need to [install Aegir](https://www.aegirproject.org) with [CiviCRM support](https://www.drupal.org/project/hosting_civicrm).

Then, with this composer template, you can create an CiviCRM platform in your Aegir at https://example.com/node/add/platform:

* name the platform as you wish, i.e.: `5.13.4+7.67`
* select `Deploy a Composer project from a Git repository`
* Docroot: `web`
* Git URL: `https://github.com/argopecten/drupal-project`
* Branch/tag: `5.13.4` or [any other tags from the repository](https://github.com/argopecten/drupal-project/releases)

## What does the template do?

When installing the given `composer.json` of this template, some tasks are taken care of:

* [Drupal 7](https://drupal.org) will be installed in the `web`-directory.
* The CiviCRM profile will be installed in the `web/profiles`-directory and all the built-in drupal profiles will be removed.
* Modules (packages of type `drupal-module`) will be placed in `web/sites/all/modules/contrib/`
* Theme (packages of type `drupal-module`) will be placed in `web/sites/all/themes/contrib/`
* Latest version of drush is installed locally for use at `vendor/bin/drush`.
