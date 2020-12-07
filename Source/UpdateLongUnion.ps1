param([string]$filepath, [string]$union_path, [int]$type_amount)

[array]$lines = @()
#$type_amount = 3
#$filepath = "E:\GitHub\RuntimeBlueprints\Source\RuntimeBlueprints\LongUnion.h"
#$union_path = "E:\Program Files\Epic Games\UE_4.23\Engine\Source\Runtime\Core\Public\Containers\Union.h"

Write-Host "Looking for Union.h in" $union_path
$union = Get-Content $union_path

$lines += $union[0]
$lines += @'

#pragma once

#include "Containers/Union.h"


'@

function Number-To-Letter {
    param([int]$Number)

    [int]$Dividend = $Number + 1
	[string]$Letter = ''
    [int]$Modulo = 0
    while ($Dividend -gt 0) {
        $Modulo = ($Dividend - 1) % 26
        $Letter =  [char](65 + $Modulo) + $Letter
        $Dividend = ($Dividend - $Modulo) / 26
    } 

    $Letter
}

function Extract-Union-Data {
    param([string]$Ref_string, [int]$Line_amount)

    [array]$Data
    
    For ([int]$i = 0; $i -lt $union.Count; $i++) {
    
        if ($union[$i] -like $Ref_string) {
                For ([int]$i2 = 0; $i2 -lt $Line_amount -1; $i2++) {
                    if ($union.Count -gt $i + $i2) {
                        [array]$Data += $union[$i + $i2]                    
                    }
                    else {
                        break
                    }

                }
            break
        }

    }
    $Data
}

[string]$template = 'template<'
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i
    if ($i -eq ($type_amount - 1)) {
        $template = $template + 'typename Type' + $Letter + '>'
    }
    else {
        $template = $template + 'typename Type' + $Letter + ', '
    }
}

$lines += $template + ''

$lines += @'
class TLongUnion
{
public:
'@

$lines += "	/** CurrentSubtypeIndex is made public instead of private for better access */"
$lines += (Extract-Union-Data -Ref_string "*The index of the subtype that the union's current value is of.*" -Line_amount 3)

$lines += (Extract-Union-Data -Ref_string "*Default constructor.*" -Line_amount 5)
$template = ((Extract-Union-Data -Ref_string "*Initialization constructor.*" -Line_amount 7) -join "`n")
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())

    $lines += $loop_template
    #$lines += ''
}

$lines += (Extract-Union-Data -Ref_string "*Copy constructor.*" -Line_amount 7)
#$extract_data = (Extract-Union-Data -Ref_string "*Copy constructor.*" -Line_amount 18)
#$template = $extract_data[9]
#Write-Host $extract_data[9]
#For ([int]$i = 0; $i -lt $type_amount; $i++) {
#
#    $Letter = Number-To-Letter -Number $i
#
#    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
#    $loop_template = $loop_template.replace('0', $i.ToString())
#
#    $lines += $loop_template
#}
#$lines += $extract_data[15]
#$lines += $extract_data[16]
#$lines += $extract_data[17]


$lines += (Extract-Union-Data -Ref_string "*Destructor.*" -Line_amount 84)
$lines += (Extract-Union-Data -Ref_string "*Sets the union's value to NULL.*" -Line_amount 6)

$extract_data = (Extract-Union-Data -Ref_string "*Sets the union's value to NULL.*" -Line_amount 14)
$template = $extract_data[6]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())

    $lines += $loop_template
}

$lines += $extract_data[12]
$lines += $extract_data[13]


$lines += (Extract-Union-Data -Ref_string "*Hash function.*" -Line_amount 8)
$extract_data = (Extract-Union-Data -Ref_string "*Hash function.*" -Line_amount 19)
$template = $extract_data[8]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())

    $lines += $loop_template
}

$lines += $extract_data[14]
$lines += $extract_data[15]
$lines += $extract_data[16]
$lines += $extract_data[17]
$lines += $extract_data[18]

$lines += (Extract-Union-Data -Ref_string "*Equality comparison.*" -Line_amount 8)
$extract_data = (Extract-Union-Data -Ref_string "*Equality comparison.*" -Line_amount 20)
$template = $extract_data[8]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())

    $lines += $loop_template
}

$lines += $extract_data[14]
$lines += $extract_data[15]
$lines += $extract_data[16]
$lines += $extract_data[17]
$lines += $extract_data[18]
$lines += $extract_data[19]

$lines += (Extract-Union-Data -Ref_string "*FArchive& Ar,TUnion& Union*" -Line_amount 11)
$extract_data = (Extract-Union-Data -Ref_string "*FArchive& Ar,TUnion& Union*" -Line_amount 37)
$template = (Extract-Union-Data -Ref_string "*FArchive& Ar,TUnion& Union*" -Line_amount 12)[11]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())

    $lines += $loop_template
}

$lines += $extract_data[17]
$lines += $extract_data[18]
$lines += $extract_data[19]
$lines += $extract_data[20]
$lines += $extract_data[21]
$lines += $extract_data[22]
$lines += $extract_data[23]
$lines += $extract_data[24]
$lines += $extract_data[25]

$template = $extract_data[26]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())

    $lines += $loop_template
}

$lines += $extract_data[32]
$lines += $extract_data[33]
$lines += $extract_data[34]
$lines += $extract_data[35]
$lines += $extract_data[36]

$lines += @'
private:
'@

$lines += (Extract-Union-Data -Ref_string "*The potential values for each subtype of the union.*" -Line_amount 4)
$extract_data = (Extract-Union-Data -Ref_string "*The potential values for each subtype of the union.*" -Line_amount 11)
$template = $extract_data[4]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('A;', $Letter + ';')

    $lines += $loop_template
}

$lines += $extract_data[10]

$lines += (Extract-Union-Data -Ref_string "*Sets the union's value to a default value of the given subtype.*" -Line_amount 8)
$lines += (Extract-Union-Data -Ref_string "*Determines the index and reference to the potential value for the given union subtype.*" -Line_amount 9)

$extract_data = (Extract-Union-Data -Ref_string "*Determines the index and reference to the potential value for the given union subtype.*" -Line_amount 80)

$template = $extract_data[9] + "`n"
$template += $extract_data[10] + "`n"
$template += $extract_data[11] + "`n"
$template += $extract_data[12] + "`n"
$template += $extract_data[13]

For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))
    $loop_template = $loop_template.replace('0', $i.ToString())
    $loop_template = $loop_template.replace('A;', $Letter + ';')

    $lines += $loop_template

    if ($i -eq 0) {
        $template = $template.replace('if(', 'else if(')
    }
}


$lines += $extract_data[39]
$lines += $extract_data[40]
$lines += $extract_data[41]

$template = $extract_data[42]
For ([int]$i = 0; $i -lt $type_amount; $i++) {

    $Letter = Number-To-Letter -Number $i

    if ($i -eq $type_amount -1) {
        $template = $template.replace('::Value ||', '::Value,')
    }

    $loop_template = $template.replace('TypeA', ('Type' + $Letter))

    $lines += $loop_template
}

$lines += $extract_data[48]
$lines += $extract_data[49]
$lines += $extract_data[50]
$lines += $extract_data[51]
$lines += $extract_data[52]
$lines += $extract_data[53]
$lines += $extract_data[54]
$lines += $extract_data[55]
$lines += $extract_data[56]
$lines += $extract_data[57]
$lines += $extract_data[58]


$lines = ($lines -join "`n").replace('TUnion', 'TLongUnion')
$lines = $lines.replace('check(CurrentSubtypeIndex == SubtypeIndex);', 'checkf((CurrentSubtypeIndex == SubtypeIndex), TEXT("Invalid SubtypeIndex, Current is %i, tested against %i"), CurrentSubtypeIndex, SubtypeIndex);')


$lines | Set-Content $filepath

Write-Host 'Updated LongUnion.h with' $type_amount 'entries in' $filepath 
	


