List of items to be added to the **unified** variable.

Each item will be added only if is defined and not empty.

This variable can contain single items, lists, dictionaries, path to files and URLs.

When specifying a path or URL item, the **titles** variable must not be empty, **titles** is used as the names of the collections to load from each file.

When specifying file paths, absolute paths must be used, is recommended to always add a *.yml* or *.yaml* extension to such files, the same applies for files specified using URLs.

This variable is empty by default.

.. substitution-code-block:: bash

 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| \
     --extra-vars "{ \
         |DEFAULT_VAR_NAME|: [  \
             itemA, itemB, itemC, \
             '/home/username/my-config.yml', \
             'https://is.gd/lnf6vn'], \
         titles: '|DEFAULT_VAR_NAME|' \
         expand: true]}"