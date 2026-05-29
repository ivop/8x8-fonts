Instructions
============

Installation
------------

The `Makefile` that generates TrueType font files, depends on the RetroFont_
package.

::

    pip instsall retrofont

From source
~~~~~~~~~~~

Install system dependencies (e.g., on a Debian system, use `apt`):

::

    apt install python3-fonttools python3-hatchling python3-yaml

Install the repository:

::

    git submodule init
    git submodule update


Usage
-----

The following command generates the TrueType font files.

::

    make

This process may take a while, if you have multiple CPU cores available, you
can use the `-j` option to speed things up. E.g., if you have 14 CPU cores,
you can run the following command:

::

    make -j 14

Additionally, the fonts can be installed using:

::

    make install

From source
~~~~~~~~~~~

If you chose to install from the source repository directly, the string
`retrofont='python -m retrofont.retrofont'` should be added to the invocation
of `make`, for example:

::
    make retrofont='python -m retrofont.retrofont'


.. _Retrofont: https://retrofont.readthedocs.io
.. _instructions: https://retrofont.readthedocs.io/en/latest/install.html
