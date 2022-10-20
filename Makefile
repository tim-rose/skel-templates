#
# Makefile --Build rules for SKEL-TEMPLATES, a library of skel(1) templates.
#
export VERSION = $(shell git describe --dirty 2>/dev/null || echo "unknown")

include makeshift.mk
