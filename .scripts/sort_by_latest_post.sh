#!/bin/bash

find . | sort -r | sed 's|./|  - blog/|g' >> ../../mkdocs.yml

