import re
#path = 'D:/GitHub/RuntimeBlueprints/Source/RuntimeBlueprints/FunctionLibraries/RandomBPLibrary.h'
path = 'D:/Program Files/Epic Games/UE_4.22/Engine/Source/Runtime/Engine/Classes/GameFramework/Pawn.h'
#path = 'D:/Program Files/Epic Games/UE_4.22/Engine/Source/Runtime/Engine/Classes/Components/PrimitiveComponent.h'
pathclass = "Pawn"

newclassname = "RuntimePawnLibrary"

cpppath = "D:/GitHub/RuntimeBlueprints/Source/RuntimeBlueprints/Nodes/RuntimePawnLibrary.cpp"
hpath = "D:/GitHub/RuntimeBlueprints/Source/RuntimeBlueprints/Nodes/RuntimePawnLibrary.h"

functionlibrary = False

# Class info in case we are converting class functions rather than library functions
custominputclasstype = "APawn*"
custominputclassname = "InPawn"
classprefix = "Pawn"

code_file = open(path, 'r')

Code_text = code_file.readlines()

Code_fulltext = code_file.read()

# print (Code_fulltext)

LoopIndex = 0
headertemplate = """[DESCRIPTION]UCLASS()
class RUNTIMEBLUEPRINTS_API U[FUNCTIONNAME] : public URuntimeBpObject
{
	GENERATED_BODY()

public:

	U[FUNCTIONNAME]();

	virtual void Execute(int Index, int FromLoopIndex = -1) override;

};"""

constructortemplate = """[FUNCTION]
{
	NodeName = "[NODENAME]";
	NodeDescription = "[NODEDESCRIPTION]";
	NodeCategory = "[NODECATEGORY]";
	
	InputPins.SetNum([INPUTAMOUNT]); [INPUTPINS]
	OutputPins.SetNum([OUTPUTAMOUNT]);
	[OUTPUTPINS]
}"""


executetemplate = ""
if functionlibrary:
    executetemplate = """void U[FUNCTIONNAME]::Execute(int Index, int FromLoopIndex)
{
    [OUTPUTVARIABLES][RETURNVALUE]U[PATHCLASS]::[FUNCTIONNAME]([WORLDCONTEXT][PARAMETERS][CLOSINGFUNCTION]
    [OUTPUTFUNCTIONS]
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}"""
else:
    executetemplate = """void U[CLASSPREFIX]_[FUNCTIONNAME]::Execute(int Index, int FromLoopIndex)
{
    if ([PATHCLASS])
    {
         [OUTPUTVARIABLES][RETURNVALUE][PATHCLASS]->[FUNCTIONNAME]([WORLDCONTEXT][PARAMETERS][CLOSINGFUNCTION]
         [OUTPUTFUNCTIONS]
    }
    else
    {
         // We make sure we at least set the return value so it resets and when getting the output pin it doesn't crash
         [RETURNVALUE][CLOSINGELSE]
    }
	Super::Execute(0, FromLoopIndex);// Index here is the array index
}"""


functioncommentlist = []
header = []
source = []

functiontypes = []
functionnames = []
argumentlist = []
nodedescriptions = []
nodecategories = []
nodepurities = []
displaynames = []

for line in Code_text:
    codeline = line

#    print(LoopIndex)
#    print (codeline)
    if line.strip().startswith("static") or (functionlibrary == False and len(Code_text) - 2 >= LoopIndex):
        codeline = codeline.strip().replace("static", "").strip()
        codeline = codeline.strip().replace("inline", "").strip()
        codeline = codeline.strip().replace("enum ", "").strip()
        codeline = codeline.strip().replace("virtual", "").strip()
        codeline = codeline.strip().replace("class ", "").strip()
        codeline = codeline.strip().replace("class", "").strip()
        codeline = codeline.strip().replace(" override", "").strip()
        codeline = codeline.strip().replace(" const;", ";").strip()        
        codeline = codeline.strip().replace(" const", "[TEMP]").strip()
        codeline = codeline.strip().replace("[TEMP] ", " const ").strip()
        codeline = codeline.strip().replace("[TEMP] ", ";").strip()
        codeline = codeline.strip().replace("[TEMP]", ";").strip()
#        if not functionlibrary:
#            codeline = codeline.strip().replace("K2_", "").strip()
#        print (Code_text[LoopIndex - 1])
#        print (codeline)
        if not (codeline.__contains__("FDateTime")
                | codeline.__contains__("FQuat")
                | codeline.__contains__("FIntPoint")
                | codeline.__contains__("FTimespan")
                | codeline.__contains__("FRandomStream")
                | codeline.__contains__("UPARAM")
                | codeline.__contains__("ReportError")
                | codeline.__contains__("FPlane")
#                | codeline.__contains__("TSubclassOf")
                | codeline.__contains__("FColor")
                | codeline.__contains__("FHitResult")
                | codeline.__contains__("TEnumAsByte")
                | codeline.__contains__("FBox")
                | codeline.__contains__("int64")
                | codeline.__contains__("FLatentActionInfo")
#                | codeline.__contains__("TArray")
                | codeline.__contains__("FPrimaryAssetId")
                | codeline.__contains__("FPrimaryAssetType")
                | codeline.__contains__("FUserActivity")
                | codeline.__contains__("FMatrix")                
                | codeline.__contains__("FFrame")
                | codeline.__contains__("FTimespan")
                | codeline.__contains__("FFrameNumber")
                | codeline.__contains__("FFrameRate")
                | codeline.__contains__("FQualifiedFrameTime")
                | codeline.__contains__("FTimerHandle")
                | codeline.__contains__("FScriptInterface")
                | codeline.__contains__("FSoftClassPath")
                | codeline.__contains__("FSoftObjectPath")
                | codeline.__contains__("TSoftObjectPtr")    
                | codeline.__contains__("TSoftClassPtr") 
                | codeline.__contains__("void*")  
                | codeline.__contains__("UChildActorComponent*")   
                | codeline.__contains__("AController*")
                | codeline.__contains__("UPawnMovementComponent*")
                | codeline.__contains__("UAnimMontage*")                 
#                | codeline.__contains__("UPrimitiveComponent*")
                | codeline.__contains__("FUserActivity") 
                | codeline.__contains__("FActorDestroyedSignature")
                | codeline.__contains__("Command") 
                | codeline.__contains__("Unattended")    
                | codeline.__contains__("ByName")
#                | codeline.__contains__("APawn")
                | codeline.__contains__("OnRep") 
                | codeline.__contains__("CCD") 
                | codeline.__contains__("return") 
                | codeline.__contains__("FWalkableSlopeOverride")
                | codeline.__contains__("UPhysicalMaterial")
                | codeline.__contains__("::")
                | codeline.__contains__("TSet")
                | codeline.__contains__("TMap")
                | codeline.__contains__("MoveIgnore")      
                | codeline.__contains__("Internal")
                | codeline.__contains__("RootMotion")   
                #Enums
                | codeline.__contains__("ESearchCase")
                | codeline.__contains__("ECollisionChannel")
                | codeline.__contains__("ECollisionResponse")
                | codeline.__contains__("ECollisionEnabled")
                | codeline.__contains__("ERadialImpulseFalloff")   
                | codeline.__contains__("EAttachmentRule")
                | codeline.__contains__("EDetachmentRule")
                | codeline.__contains__("ETickingGroup")                
#                | codeline.__contains__("K2_")                            
                # Prints are handled separately
                | codeline.__contains__("PrintString")
                | codeline.__contains__("PrintText")
                | codeline.__contains__("PrintWarning")
#                | codeline.__contains__("Random") # No functions which does random generation as they are not threadsafe, will have a separate library for those
                | Code_text[LoopIndex + 1].__contains__("FTimespan") # check for the line below for multiline params
                | Code_text[LoopIndex + 1].__contains__("FRandomStream")
                | Code_text[LoopIndex + 1].__contains__("UPARAM") # disable this when UPARAMS are handled properly
                | Code_text[LoopIndex + 1].__contains__("ReportError")
                | Code_text[LoopIndex + 1].__contains__("FPlane")
#                | Code_text[LoopIndex + 1].__contains__("TSubclassOf")
                | Code_text[LoopIndex + 1].__contains__("FColor")
                | Code_text[LoopIndex + 1].__contains__("FHitResult")
                | Code_text[LoopIndex + 1].__contains__("TEnumAsByte")
                | Code_text[LoopIndex + 1].__contains__("FBox")
                | Code_text[LoopIndex + 1].__contains__("FLatentActionInfo")                  
                # BlueprintInternalUseOnly should not be called from C++ so they are excluded
                | Code_text[LoopIndex - 1].__contains__("BlueprintInternalUseOnly")
                # BlueprintImplementableEvent has a similar story to it  
                | Code_text[LoopIndex - 1].__contains__("BlueprintImplementableEvent")
#                | Code_text[LoopIndex + 1].__contains__("TArray") #For now remove arrays until they're supported
                # Remove any functions that we don't want the end user to mess with
                | Code_text[LoopIndex - 2].__contains__("DEPRECATED")
                | Code_text[LoopIndex - 1].__contains__("DEPRECATED")
                | Code_text[LoopIndex - 1].__contains__("Editor")
                | Code_text[LoopIndex - 1].__contains__("Platform")
                | Code_text[LoopIndex - 1].__contains__("Game")                
                | Code_text[LoopIndex - 1].__contains__("Online")
                | Code_text[LoopIndex - 1].__contains__("Paths")     
                | Code_text[LoopIndex - 1].__contains__("SoftClassPath")                 
                | Code_text[LoopIndex - 1].__contains__("Rendering")
                | Code_text[LoopIndex - 1].__contains__("Time Management")
                | Code_text[LoopIndex - 1].__contains__("Transactions")
                | Code_text[LoopIndex - 1].__contains__("AssetManager")
#                | Code_text[LoopIndex - 1].__contains__("CustomThunk")
                | Code_text[LoopIndex - 1].__contains__("Development")
                | Code_text[LoopIndex - 1].__contains__("Replication")
                | Code_text[LoopIndex - 1].__contains__("Networking")
                | Code_text[LoopIndex - 1].__contains__("unreliable")                
                | Code_text[LoopIndex - 1].__contains__("AI")
                | Code_text[LoopIndex - 1].__contains__("Input")
                | Code_text[LoopIndex - 1].__contains__("dependency")
                | Code_text[LoopIndex - 1].__contains__("Debug")) and Code_text[LoopIndex - 1].__contains__("UFUNCTION"):

            functiontype = codeline.split(" ", 1)[0]
            functiontypes.append(functiontype)
            function = codeline.split(" ", 1)[1]
#            print(functiontype)
#            print(codeline)
            print(function)
            # functionality for functions that have the parameters on multiple lines
            if not function.endswith(";") and not function.endswith(")"):
                MultilineIndex = 0
                multilinefunction = []
                # print (str(len(Code_text)))
                # print (str(LoopIndex + MultilineIndex))
                while not Code_text[LoopIndex + MultilineIndex].strip().endswith(";"):
#                    print (Code_text[LoopIndex + MultilineIndex])
                    MultilineIndex += 1
                    function = function + Code_text[LoopIndex + MultilineIndex].strip()
                    # print (str(MultilineIndex))
                # function = function + Code_text[LoopIndex + MultilineIndex]
#                print(function)
                if function.__contains__("UPARAM"):
                    leftfunction = function.split("UPARAM(")[0]
#                    print(leftfunction)
                    rightfunction = function.split(')', 1)[1]
#                    print(rightfunction)

            # Functionality for removing UPARAMs

            # Split the category
            
            category = ""
            
            if Code_text[LoopIndex - 1].__contains__("Category = "):
                category = Code_text[LoopIndex - 1].split("Category = ")[1]
                if category.__contains__('"'):
                    category = category.split('"')[1]
                    category = category.split('"')[0]
                category = category.split(')')[0]    
#                print(category)

            elif Code_text[LoopIndex - 1].__contains__("Category="):
                category = Code_text[LoopIndex - 1].split("Category=")[1]
                if category.__contains__('"'):
                    category = category.split('"')[1]
                    category = category.split('"')[0]
                category = category.split(')')[0] 
                # print(category)

            
            if not functionlibrary and not category.startswith(classprefix):
                if category == "":
                    category = classprefix
                else:
                    category = classprefix + "|" + category
                
            nodecategories.append(category)
            
            # Get the displayname if it exists
            displayname = ""
            
            if Code_text[LoopIndex - 1].__contains__("DisplayName = "):
                displayname = Code_text[LoopIndex - 1].split("DisplayName = ")[1]
                if displayname.__contains__('"'):
                    displayname = displayname.split('"')[1]
                    displayname = displayname.split('"')[0]
                displayname = displayname.split(')')[0]    
#                print(displayname)

            elif Code_text[LoopIndex - 1].__contains__("DisplayName="):
                displayname = Code_text[LoopIndex - 1].split("DisplayName=")[1]
                if displayname.__contains__('"'):
                    displayname = displayname.split('"')[1]
                    displayname = displayname.split('"')[0]
                displayname = displayname.split(')')[0] 
                # print(displayname)
                
            displaynames.append(displayname)
            
            arguments = function.split("(", 1)[1].rsplit(")", 1)[0]
#            print (arguments)
            argumentlist.append(arguments)
            
#            print(functionname)
            functionname = function.split("(", 1)[0]
#            functionname.replace("K2_", "")
            functionnames.append(functionname)

#            print(functionname)

            functioncommentindex = LoopIndex - 2
            # print(Code_text[functioncommentindex])
            localfunctioncommentlist = []

            while Code_text[functioncommentindex].strip().startswith("/") | Code_text[functioncommentindex].strip().startswith("*"):
                localfunctioncommentlist.append(Code_text[functioncommentindex].strip())
                # print(Code_text[functioncommentindex].strip())
                functioncommentindex -= 1

            functioncommentlist.append("\n".join(localfunctioncommentlist[::-1]))
            
            if functionlibrary:
                headertext = headertemplate.replace("[FUNCTIONNAME]", functionname)
            else:
                headertext = headertemplate.replace("[FUNCTIONNAME]", classprefix + "_" + functionname)
            headertext = headertext.replace("[DESCRIPTION]", "\n".join(localfunctioncommentlist[::-1]) + "\n")
            header.append(headertext)

            nodedescription = []
            # Add the the description to the variable in the constructor
            for comment in localfunctioncommentlist:
                comment = comment.replace('/', '')
                comment = comment.replace('*', '')
                comment = comment.replace('"', "'")
                comment = comment.strip()
#                print(comment)
#                comment = comment + "|"
                # comment = '\n   "' + comment + '"'
                comment = comment.replace('""', '')
                # if not comment.__contains__('""'):
                nodedescription.append(comment)

            # 2 ifs in for both pops
            if len(nodedescription) > 1:
                nodedescription.pop()
                if len(nodedescription) > 1:
                    nodedescription.pop(0)

            nodedescriptions.append(nodedescription)
            
            #This determines wether a function is pure or not
            nodepurity = False
            if (Code_text[LoopIndex - 1].__contains__("BlueprintPure") or line.strip().__contains__(" const") and not line.strip().__contains__(", const")) and functiontype != "void":
                nodepurity = True
            nodepurities.append(nodepurity)            
            
    LoopIndex += 1

LoopIndex = 0

# create headers
# for function in header:
#
#     print(functioncommentlist[LoopIndex])
#     print(function)
#     print ("")
#
#     LoopIndex += 1

LoopIndex = 0

# create cpp
for functionname in functionnames:
    
    if functionlibrary:
        function = "U[FUNCTIONNAME]::U[FUNCTIONNAME]()".replace("[FUNCTIONNAME]", functionname)
    else:
        function = "U[FUNCTIONNAME]::U[FUNCTIONNAME]()".replace("[FUNCTIONNAME]", classprefix + "_" + functionname)

 
#    print(functionname)
    usesworldcontext = False
    # nodename = functionname
    # set rules for node names
    nodename = ""
    if displaynames[LoopIndex] == "":
        nodename = re.sub(r"([a-z])([A-Z])", r"\1 \2", functionname).replace("K2_", "").replace("_", " ")
    else:
        nodename = re.sub(r"([a-z])([A-Z])", r"\1 \2", displaynames[LoopIndex]).replace("K2_", "").replace("_", " ")

    nodedescription = nodedescriptions[LoopIndex]
    nodecategory = nodecategories[LoopIndex]
    functiontype = functiontypes[LoopIndex]

    if functiontype == "bool":
        functiontype = "Bool"
    elif functiontype.startswith("class"):
        functiontype.split(" ", 1)
    functiontype.replace("*", "")


    inputpins = []
    outputpins = []
    functionargs = []
    outputpinvars = []
    outputargs = []
    returnvaluearg = ""
    meta = ""
    
    # If the node isn't pure, we add exec pins
    pure = nodepurities[LoopIndex]
    if not pure:
        inputpins.insert(0, 'InputPins[0].MakeNodePin();// No args means execute')
        outputpins.insert(0, 'OutputPins[0].MakeNodePin("Then");// Output exec pin')
        
    # We init the return value if the function type isn't a void
    if functiontype != "void":
        isarray = False
        
        if functiontype.__contains__("TArray"):
            functiontype = functiontype.split(">")[0]
            functiontype = functiontype.split("<")[1].strip()
            if functiontype.__contains__("class "):
                functiontype = functiontype.replace("class ", "", 0)
            isarray = True
        
        if functiontype.__contains__("TSubclassOf") or functiontype.__contains__("TSubOf"):
            functiontype = functiontype.split(">")[1].strip()
            functiontype = "Uclass " + functiontype
            print (functiontype)
	
        functiontype = functiontype.title()
        
        if functiontype.startswith("E"):
            meta = functiontype
            functiontype = "Byte"
		
	functiontype = functiontype.lower()
        if functiontype == "uint8":
            functiontype = "Byte"
        elif functiontype.startswith("flinear"):
            functiontype = "LinearColor"
        elif functiontype == "bool":
            functiontype = "Bool"
        elif functiontype == "float":
            functiontype = "Float"
        elif "uobject" in functiontype
            functiontype = "Object"
        elif "scenecomponent" in functiontype:
            functiontype = "SceneComponent"
        elif "uprimitivecomponent" in functiontype:
            functiontype = "PrimitiveComponent"
	elif "aactor" in functiontype:
            functiontype = "Actor"
        elif "acharacter" in functiontype:
            functiontype = "Character"
        elif "apawn" in functiontype:
            functiontype = "Pawn"
        elif "uclass" in functiontype:
            functiontype = "Class"
        elif functiontype == "int32" or functiontype == "int":
            functiontype = "Int"
        elif functiontype == "fvector":
            functiontype = "Vector"
        elif functiontype == "frotator":
            functiontype = "Rotator"
        elif functiontype == "ftransform":
            functiontype = "Transform"
        elif functiontype == "fstring":
            functiontype = "String"
        elif functiontype == "ftext":
            functiontype = "Text"
        elif functiontype == "fname":
            functiontype = "Name"
        elif functiontype == "fvector2d":
            functiontype = "Vector2D"
        elif functiontype == "fintVector":
            functiontype = "IntVector"
        elif functiontype == "fvector4":
            functiontype = "Vector4"
        elif "ustaticmeshcomponent" in functiontype:
            functiontype = "StaticMeshComponent"
        elif "umeshcomponent" in functiontype:
            functiontype = "StaticMeshComponent"
        elif "ustaticmesh" in functiontype:
            functiontype = "StaticMesh"
        elif "umaterialinterface" in functiontype:
            functiontype = "MaterialInterface"
	
        if pure:
            if isarray:
                outputpins.insert(0, 'OutputPins[0].MakeNodeArray("Return", EVariableTypes::' + functiontype + ');// PinName + PinType')
                returnvaluearg = 'OutputPins[0].Value.Set' + functiontype + 'Arg('.strip()
            else:
                outputpins.insert(0, 'OutputPins[0].MakeNodePin("Return", EVariableTypes::' + functiontype + ');// PinName + PinType')
                returnvaluearg = 'OutputPins[0].Value.Array[0].Set' + functiontype + 'Arg('.strip()
        else:
            if isarray:
                outputpins.insert(1, "\n    " + 'OutputPins[1].MakeNodeArray("Return", EVariableTypes::' + functiontype + ');// PinName + PinType')
                returnvaluearg = 'OutputPins[1].Value.Set' + functiontype + 'Arg('.strip()
            else:
                outputpins.insert(1, "\n    " + 'OutputPins[1].MakeNodePin("Return", EVariableTypes::' + functiontype + ');// PinName + PinType')
                returnvaluearg = 'OutputPins[1].Value.Array[0].Set' + functiontype + 'Arg('.strip()


    splitargs = argumentlist[LoopIndex].split(", ")
    
    # We insert the class type of the class of which the internal function can be called
    if not functionlibrary:
        splitargs.insert(0, custominputclasstype + " " + custominputclassname)
    
    
    for pinname in splitargs:
        if pinname.__contains__("WorldContextObject"):
            usesworldcontext = True

    # Assign split arguments
    InputPinLoopIndex = len(inputpins)
    OutputPinLoopIndex = len(outputpins)

    for pinname in splitargs:
        if not pinname == "":

            usesworldcontext = pinname.__contains__("WorldContextObject")
            pinname = pinname.replace("class ", "")
            pinname = pinname.strip()

            isinput = True
            isarray = False

            pintype = ""
            localpinname = ""
            defaultvalue = ""
            functionarg = ""
            
            # Exception rule for const
            if pinname.startswith("const"):
                # Isolate the variable type
                pintype = pinname.split(" ", 1)[1]
                pintype = pintype.split(" ", 1)[0]
		
                # Now split pinname along with the potential default value
                localpinname = pinname.split(" ", 1)[1].split(" ", 1)[1]
                if len(localpinname.split("=", 1)) > 1:
                    localpinname = localpinname.split("=", 1)[0].strip()

                # Remove the & if it's there
                pintype = pintype.split("&", 1)[0].strip()

            else:
                localpinname = ""
                pintype = pinname.split(" ", 1)[0]
                if pinname.__contains__("&"):
                    isinput = False
                    pintype = pintype.split("&")[0]
                    localpinname = pinname.split("&")[1].strip()
                    
                    # We fix the pinname to make sure that the & is in the right location for the rest of the functions
                    pinname = pintype + "& " + localpinname
                else:
                    localpinname = pinname.split(" ")[1]
                
            if pinname.strip().__contains__("TArray"):
                pintype = pintype.split(">")[0]
                pintype = pintype.split("<")[1].strip()
#                print (pintype)
                isarray = True
#                print(functionname)
#            print(pinname)
            if pinname.strip().__contains__("TSubOf"):
                pintype = pintype.split(">")[1].strip()
                pintype = "Uclass " + pintype
#                print (pintype)

            if len(pinname.split("=", 1)) > 1:
                    defaultvalue = pinname.split("=", 1)[1].strip()
                    # print(defaultvalue)
            
#            print(pinname)
#            print(pintype)
            localpinname = re.sub(r"([a-z])([A-Z])", r"\1 \2", localpinname).replace("_", " ")

            makedefaultvalue = ""

            pintype = pintype.capitalize()
            if pintype.startswith("E"):
                pintype = "Byte"
                variabletype = "uint8"
		
	    pintype = pintype.lower()
            if pintype == "uint8":
                pintype = "Byte"
                variabletype = "uint8"
            elif pintype == "bool":
                pintype = "Bool"
                variabletype = "bool"
            elif pintype == "float":
                pintype = "Float"
                variabletype = "float"
            elif pintype == "int" or pintype == "int32":
                pintype = "Int"
                variabletype = "int"
            elif pintype.startswith("flinear"):
                pintype = "LinearColor"
                variabletype = "FLinearColor"
            elif "uobject" in pintype:
                pintype = "Object"
                variabletype = "UObject*"
            elif "uscenecomponent" in pintype:
                pintype = "SceneComponent"
                variabletype = "USceneComponent*"
            elif "uprimitivecomponent" in pintype:
                pintype = "PrimitiveComponent"
                variabletype = "UPrimitiveComponent*"
            elif "aactor" in pintype:
                pintype = "Actor"
                variabletype = "AActor*"
            elif "acharacter" in pintype:
                pintype = "Character"
                variabletype = "ACharacter*"
            elif "apawn" in pintype:
                pintype = "Pawn"
                variabletype = "APawn*"
            elif "uclass" in pintype:
                pintype = "Class"
                variabletype = "UClass*"
            elif pintype == "fvector":
                pintype = "Vector"
                variabletype = "FVector"
            elif pintype == "frotator":
                pintype = "Rotator"
                variabletype = "FRotator"
            elif pintype == "ftransform":
                pintype = "Transform"
                variabletype = "FTransform"
            elif pintype == "fstring":
                pintype = "String"
                variabletype = "FString"
            elif pintype == "ftext":
                pintype = "Text"
                variabletype = "FText"
            elif pintype == "fname":
                pintype = "Name"
                variabletype = "FName"
            elif pintype == "fvector2d":
                pintype = "Vector2D"
                variabletype = "FVector2D"
            elif pintype == "fintvector":
                pintype = "IntVector"
                variabletype = "FIntVector"
            elif pintype == "FVector4":
                pintype = "Vector4"
                variabletype = "FVector4"
            elif "ustaticmeshcomponent" in pintype:
                pintype = "StaticMeshComponent"
                variabletype = "UStaticMeshComponent*"
            elif "umeshcomponent" in pintype:
                pintype = "StaticMeshComponent"
                variabletype = "UStaticMeshComponent*"
            elif "ustaticmesh" in pintype:
                pintype = "StaticMesh"
                variabletype = "UStaticMesh*"
            elif "umaterialinterface" in pintype:
                pintype = "MaterialInterface"
                variabletype = "UMaterialInterface*"

            if isinput and not usesworldcontext:
                if isarray:
                    makenode = 'InputPins[' + str(InputPinLoopIndex) + '].MakeNodeArray("' + localpinname + '", EVariableTypes::' + pintype + ');// PinName + PinType'
                    if functionlibrary:
                        functionarg = 'GetConnectedPinArray(InputPins[' + str(InputPinLoopIndex) + ']).Get' + pintype + 'Arg()'
                        functionargs.append(functionarg)  
                    else:
                        if variabletype == custominputclasstype and localpinname.replace(" ", "") == custominputclassname:
                            pathclass = 'GetConnectedPinArray(InputPins[' + str(InputPinLoopIndex) + ']).Get' + pintype + 'Arg()'
                        else:
                            functionarg = 'GetConnectedPinArray(InputPins[' + str(InputPinLoopIndex) + ']).Get' + pintype + 'Arg()'
                            functionargs.append(functionarg)
                    makedefaultvalue = 'InputPins[' + str(InputPinLoopIndex) + '].Value.Set' + pintype + 'Arg(' + defaultvalue + '); // Default value'
                else:
                    makenode = 'InputPins[' + str(InputPinLoopIndex) + '].MakeNodePin("' + localpinname + '", EVariableTypes::' + pintype + ');// PinName + PinType'
                    if functionlibrary:
                        functionarg = 'GetConnectedPinValue(InputPins[' + str(InputPinLoopIndex) + ']).Get' + pintype + 'Arg()'
                        functionargs.append(functionarg)  
                    else:
                        if variabletype == custominputclasstype and localpinname.replace(" ", "") == custominputclassname:
                            pathclass = 'GetConnectedPinValue(InputPins[' + str(InputPinLoopIndex) + ']).Get' + pintype + 'Arg()'
                        else:
                            functionarg = 'GetConnectedPinValue(InputPins[' + str(InputPinLoopIndex) + ']).Get' + pintype + 'Arg()'
                            functionargs.append(functionarg)  
                    makedefaultvalue = 'InputPins[' + str(InputPinLoopIndex) + '].Value.Array[0].Set' + pintype + 'Arg(' + defaultvalue + '); // Default value'
                
                InputPinLoopIndex += 1

                if makedefaultvalue == "":
                    inputpins.append(makenode + "\n	")
                else:
                    inputpins.append(makenode + "\n	" + makedefaultvalue + "\n")

            elif not usesworldcontext:
                
                if isarray:
                    makenode = 'OutputPins[' + str(OutputPinLoopIndex) + '].MakeNodeArray("' + localpinname + '", EVariableTypes::' + pintype + ');// PinName + PinType'
                    variable = "TArray<" + variabletype + "> " + pinname.split(" ")[1] + ";"
                    outputpinvars.append(variable.strip())
                    outputarg = 'OutputPins[' + str(OutputPinLoopIndex) + '].Value.Set' + pintype + 'Arg(' + pinname.split(" ")[1] + ');'
                    outputargs.append(outputarg)
                    functionarg = pinname.split(" ")[1]
                    functionargs.append(functionarg)
                
                else:
                    makenode = 'OutputPins[' + str(OutputPinLoopIndex) + '].MakeNodePin("' + localpinname + '", EVariableTypes::' + pintype + ');// PinName + PinType'
                    variable = variabletype + " " + pinname.split(" ")[1] + ";"
                    outputpinvars.append(variable.strip())
                    outputarg = 'OutputPins[' + str(OutputPinLoopIndex) + '].Value.Array[0].Set' + pintype + 'Arg(' + pinname.split(" ")[1] + ');'
                    outputargs.append(outputarg)
                    functionarg = pinname.split(" ")[1]
                    functionargs.append(functionarg)

                OutputPinLoopIndex += 1
                outputpins.append("\n    " + makenode)

    PinLoopIndex = 0

    for pinname in splitargs:
        if pinname.__contains__("WorldContextObject"):
            usesworldcontext = True

    constructor = constructortemplate
    constructor = constructor.replace("[FUNCTION]", function)
    constructor = constructor.replace("[NODENAME]", nodename)

    constructor = constructor.replace("[NODEDESCRIPTION]", "".join(nodedescription[::-1]))
    constructor = constructor.replace("[NODECATEGORY]", nodecategory)

    if len(inputpins) > 0:
        constructor = constructor.replace("[INPUTAMOUNT]", str(len(inputpins)))
        constructor = constructor.replace("[INPUTPINS]", "\n	"+ "\n	".join(inputpins))
    else:
        constructor = constructor.replace("InputPins.SetNum([INPUTAMOUNT]);", "")
        constructor = constructor.replace("[INPUTPINS]", "")

    constructor = constructor.replace("[OUTPUTAMOUNT]", str(len(outputpins)))
    constructor = constructor.replace("[OUTPUTPINS]", "    ".join(outputpins))

    # print(constructor)

    execute = executetemplate
    # print(functionargs)
    
    args = ", ".join(functionargs)
    args.strip()

    execute = execute.replace("[FUNCTIONNAME]", functionname)
    execute = execute.replace("[CLASSPREFIX]", classprefix)
    execute = execute.replace("[PATHCLASS]", pathclass)
    if functiontype != "void":
#        print(execute)
        if len(outputpinvars) > 0:
            execute = execute.replace("[RETURNVALUE]", "	" + returnvaluearg.strip())        
        else:
            execute = execute.replace("[RETURNVALUE]", "" + returnvaluearg.strip())             
        
        execute = execute.replace("[CLOSINGFUNCTION]", "));")
        execute = execute.replace("[CLOSINGELSE]", ");")
        # print(execute)
    else:
        execute = execute.replace("[RETURNVALUE]", "	")
        execute = execute.replace("[CLOSINGFUNCTION]", ");")
        execute = execute.replace("[CLOSINGELSE]", "")

    if len(outputpinvars) > 0:
        execute = execute.replace("[OUTPUTVARIABLES]", ("\n" + "	").join(outputpinvars).strip().rstrip() + "\n")
        execute = execute.replace("[OUTPUTFUNCTIONS]", "\n	" + "\n	".join(outputargs) + "\n")
    else:
        execute = execute.replace("[OUTPUTVARIABLES]", "\n	")
        execute = execute.replace("[OUTPUTFUNCTIONS]", "    ")
    if usesworldcontext:
        if len(functionargs) > 0:
            execute = execute.replace("[WORLDCONTEXT]", "this,")
            execute = execute.replace("[PARAMETERS]", " " + args)
        else:
            execute = execute.replace("[WORLDCONTEXT]", "this")
            execute = execute.replace("[PARAMETERS]", "")
    else:
        if len(functionargs) > 0:
            execute = execute.replace("[WORLDCONTEXT]", "")
            execute = execute.replace("[PARAMETERS]", "" + args)
        else:
            execute = execute.replace("[WORLDCONTEXT]", "")
            execute = execute.replace("[PARAMETERS]", "")

    # print(execute)

    source.append(constructor)
    source.append("\n")
    source.append(execute)
    source.append("\n")

    LoopIndex += 1

# print("\n".join(source))

header.insert(0, "// Fill out your copyright notice in the Description page of Project Settings.")
header.insert(1, "#pragma once")
header.insert(2, '''#include "CoreMinimal.h"
#include "RuntimeBpObject.h"
#include "Components/PrimitiveComponent.h"
#include "RuntimePawnLibrary.generated.h"
''')

source.insert(0, '''// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimePawnLibrary.h"
#include "RuntimeBpConstructor.h"
''')

cpp = "\n".join(source)
# print(cpp)
cppfile = open(cpppath, "w")
cppfile.write(cpp)
cppfile.close()

h = "\n\n".join(header)
# print(h)
hfile = open(hpath, "w")
hfile.write(h)
hfile.close()
