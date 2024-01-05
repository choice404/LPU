    ADD R0 R1
    ADI R1 34
    ADD R0 R1
    ADI R1 34
_test:
    CMP R1 R0
    BNE _test ; test comment 1
    ADD R5 R2 ; test comment 2
    ; Comment
    BNE _test
