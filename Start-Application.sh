applicationPath="/aug-compiler/out/parser.o"

if [ $# -eq 1 ]; then
    applicationPath="$applicationPath $1"
fi

docker exec -it parsing-dev-tools bash -c "$applicationPath"