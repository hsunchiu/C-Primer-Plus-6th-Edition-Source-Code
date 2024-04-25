#!/bin/bash
for i in {1..600}; do echo $(($RANDOM % 10)); done | xargs -n 20

