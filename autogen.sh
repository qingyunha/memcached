#!/bin/sh
#
# This is hacky, because there are so many damn versions
# of autoconf/automake.  It works with Debian woody, at least.
# 

echo "aclocal..."
$ACLOCAL || aclocal-1.7 || aclocal-1.5 || exit 1

echo "autoheader..."
AUTOHEADER=${AUTOHEADER:-autoheader}
$AUTOHEADER || exit 1

echo "automake..."
AUTOMAKE=${AUTOMAKE:-automake-1.7}
$AUTOMAKE --gnu --add-missing || automake --gnu --add-missing || exit 1

echo "autoconf..."
AUTOCONF=${AUTOCONF:-autoconf}
$AUTOCONF || exit 1

