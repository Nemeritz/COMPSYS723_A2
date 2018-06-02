MAIN_MODULE="CruiseController"

mkdir -p Build
find Src/ -maxdepth 1 -iname "*.strl" -not -name "$MAIN_MODULE.strl" -exec cat {} +> Build/$MAIN_MODULE.strl
cat "Src/$MAIN_MODULE.strl" >> "Build/$MAIN_MODULE.strl"
find Src/ -name \*.h -exec cp {} Build \;
find Src/ -name \*.c -exec cp {} Build \;
cp Src/Makefile Build/Makefile
cd Build
make CruiseController.xes
cd ..
