
FROM gcc:latest as build
WORKDIR /docker_build
COPY . .
RUN apt-get update && apt-get install -y cmake
RUN mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

FROM gcc:latest as lab_1_tests
WORKDIR /docker_build
COPY --from=build /docker_build/build/lab_1_tests ./
CMD ["./lab_1_tests"]

FROM gcc:latest as lab_1
WORKDIR /docker_build
COPY --from=build /docker_build/build/lab_1 ./
CMD ["./lab_1"]