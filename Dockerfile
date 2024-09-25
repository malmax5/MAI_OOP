FROM gcc:latest as build
WORKDIR /docker_build
COPY . .
RUN rm -rf build
RUN apt-get update && apt-get install -y cmake
RUN mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .

FROM gcc:latest as lab_2_tests
WORKDIR /docker_build
COPY --from=build /docker_build/build/lab_2_tests ./
CMD ["./lab_2_tests"]

FROM gcc:latest as lab_2
WORKDIR /docker_build
COPY --from=build /docker_build/build/lab_2 ./
CMD ["./lab_2"]