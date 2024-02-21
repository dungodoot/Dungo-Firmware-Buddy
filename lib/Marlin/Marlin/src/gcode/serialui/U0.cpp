#include "../gcode.h"
#include "../../core/serial.h"
#include "feature/serial_ui.h"

/**
 * U0: Handle MsgBox using G-code
 *
 *  Sn Response to MsgBox
 *
 */
void GcodeSuite::U0() {
  if (parser.seenval('S')) {
    int8_t response_index = parser.value_byte();
    msgbox_response = response_index;
    msgbox_done = true;
    SERIAL_ECHO_START();
    SERIAL_ECHO("triggering response ");
    SERIAL_ECHOLN(msgbox_response);
  }
}
