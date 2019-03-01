<title>EpsSender Component Dictionary</title>
# EpsSender Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|PS_FIND_POWER|0 (0x0)|Get power| | |   
| | | |val1|F32|The first value|                    
| | | |val2|F32|The second value|                    
| | | |operation|EpsOp|The operation to perform|                    

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|PS_VAL1|0 (0x0)|F32|The first value|
|PS_VAL2|1 (0x1)|F32|The second value|
|EPS_OP|2 (0x2)|EpsTlm|The operation|
|EPS_RES|3 (0x3)|F32|The result|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|EPS_COMMAND_RECV|0 (0x0)|Power value received| | | | |
| | | |val1|F32||The val1 argument|    
| | | |val2|F32||The val2 argument|    
| | | |op|EpsEv||The requested operation|    
|EPS_RESULT|1 (0x1)|Received power result| | | | |
| | | |result|F32||The power result|    
