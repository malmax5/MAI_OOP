#!/bin/bash

docker build -t docker-cpp-lab_1_tests -f Dockerfile --target lab_1_tests . --no-cache
docker build -t docker-cpp-lab_1 -f Dockerfile --target lab_1 . --no-cache

docker run docker-cpp-lab_1_tests
docker run docker-cpp-lab_1