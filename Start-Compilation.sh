makeCommand="make"

if [ $# -eq 1 ]; then
    makeCommand="$makeCommand $1"
fi

docker exec -it parsing-dev-tools bash -c "cd /aug-compiler/src/ && $makeCommand"