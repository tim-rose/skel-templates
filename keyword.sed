#!/usr/bin/sed -f
# SAMPLE.SED --Per-project substitutions for skeletons.
#
s/\<COPYRIGHT\>/Copyright \(c\) YEAR AUTHOR. All rights reserved./g
s/\<YEAR\>/2023/g
s/\<AUTHOR\>/Tim Rose/g
s/\<CONTACT\>/tim.rose@acm.org/g
s/\<PROJECT-ID\>/999/g
s/\<PROJECT\>/Tinkerola/g
s/\<CLIENT\>/Acme Products/g
