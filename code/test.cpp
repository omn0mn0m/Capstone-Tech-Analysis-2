TEST_CASE( "Testing command functions", "[read_command]" ) {
    set_pin_val(PORT_IR_0, 1000);
    setup();

    SECTION("Testing recalibrate command") {
        int initial_ir_val = ir_0.ambient_lvl;

        set_pin_val(PORT_IR_0, 3000);
        SerialBT.set_data_in(COM_RECALIBRATE);
        read_command();

        int new_ir_val = ir_0.ambient_lvl;

        REQUIRE((initial_ir_val == 1000 && new_ir_val == 3000));
    }

    SECTION("Testing manual position reading") {
        SerialBT.set_data_in(COM_GET_POS);
        read_command();

        REQUIRE(SerialBT.get_data_out() == POS_UHOH);
    }
}