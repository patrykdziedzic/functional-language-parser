ScriptPath="$( cd "$( dirname "$0" )" >/dev/null && pwd )"
docker run --name parsing-dev-tools -t -d -v "$ScriptPath"/aug-compiler:/aug-compiler knordman/bison-flex-builder