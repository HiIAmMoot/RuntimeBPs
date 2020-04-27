import re

datapath = 'D:\GitHub\RuntimeBlueprints\Source\RuntimeBlueprints\RuntimeBpData.h'

cpppath = 'D:\GitHub\RuntimeBlueprints\Source\RuntimeBlueprints\RuntimeBpLibrary.cpp'
hpath = 'D:\GitHub\RuntimeBlueprints\Source\RuntimeBlueprints\RuntimeBpLibrary.h'
hwritepath = 'D:\GitHub\RuntimeBlueprints\Source\RuntimeBlueprints\RuntimeBpLibrary.h'

data_file = open(datapath, 'r')

types = ""
for data_line in data_file:
    if data_line.__contains__("TLongUnion") and not data_line.__contains__("/"):
        unionline = data_line.strip().replace("TLongUnion<", "")
        unionline = unionline.strip().replace("> VariableData;", "").strip()
        types = unionline.split(", ")
        # for type in types:
        #     print(type)


template = '''	// Gets the variable in the form of an [POINTLESSTYPE]
	UFUNCTION(BlueprintPure, meta = (Category = "Virtual Values|Get", Keywords = "Get Node Var Args [DESCRIPTIONTYPE]"))
	static TArray<[TYPE]> Get[POINTLESSTYPE]Arg(UPARAM(ref)FPinStruct& PinStruct);

	// Sets the variable in the form of an [POINTLESSTYPE]
	UFUNCTION(BlueprintCallable, meta = (Category = "Virtual Values|Set", Keywords = "Set Node Var Args [DESCRIPTIONTYPE]")) 
	static void Set[POINTLESSTYPE]Arg(UPARAM(ref)FPinStruct& PinStruct, TArray<[TYPE]> Value);
	'''

hpath_file = open(hpath, 'r')
LoopIndex = 0
ScriptInsertIndex = -1

hpath_code = []
for path_line in hpath_file:
    # print(path)
    if path_line.__contains__("~~PYTHON SCRIPT IDENTIFIER~~"):
        ScriptInsertIndex = LoopIndex
    LoopIndex += 1
    hpath_code.append(path_line)

hpath_file = open(hpath, 'r')
types.reverse()

for type in types:
    pointlesstype = type.replace("*", "")
    descriptiontype = re.sub(r"([a-z])([A-Z])", r"\1 \2", pointlesstype).replace("_", " ")
    if descriptiontype[1].isupper():
        descriptiontype = descriptiontype.replace(descriptiontype[0], "", 1)

    typecode = template.replace("[POINTLESSTYPE]", pointlesstype)
    typecode = typecode.replace("[DESCRIPTIONTYPE]", descriptiontype)
    typecode = typecode.replace("[TYPE]", type)



    typeexists = False
    for path_line in hpath_code:
        # print(path_line)
        if path_line.__contains__("static " + type) | path_line.__contains__("static void Set" + pointlesstype):
            # print(type)
            typeexists = True
    if not typeexists:
        # print(typecode)
        hpath_code.insert(ScriptInsertIndex + 1, typecode)

for hpath_line in hpath_code:
    print(hpath_line)

hwritefile = open(hwritepath, "w")
h = "\n".join(hpath_code)
hwritefile.write(h)
hwritefile.close()