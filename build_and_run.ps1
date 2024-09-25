docker build -t docker-cpp-lab_2_tests -f Dockerfile --target lab_2_tests .
docker build -t docker-cpp-lab_2 -f Dockerfile --target lab_2 .

docker run docker-cpp-lab_2_tests
docker run docker-cpp-lab_2