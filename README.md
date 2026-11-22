# Actuator Control Board — CAN Protocol

This board controls 32 actuator outputs using four cascaded SN74HC595 shift registers.

**Important:** Always send exactly 4 data bytes on ID 200 (0x0C8), or the message will be ignored.

**Important:** On Actuator board PCB, each actuator pin is labeled and it is synced with corresponding bits in code.

## CAN Configuration

| Parameter | Value |
|---|---|
| Protocol | Classic CAN 2.0 |
| Bitrate | 500 kbit/s |
| CAN ID | 200 (decimal) / 0x0C8 |
| Identifier | Standard (11-bit) |
| Frame type | Data frame |
| DLC | 4 bytes |
| Byte order | Big-endian |

## Message Format

The CAN message contains a 32-bit unsigned integer (`uint32_t`) representing the state of all 32 actuator outputs.

Each bit controls one actuator:

- `0` - Actuator OFF
- `1` - Actuator ON

Considering big-endian, this is the corresponding bytes to actuators.

| Byte | Content |
|---|---|
| Data[3] | Actuators 0-7 |
| Data[2] | Actuators 8-15 |
| Data[1] | Actuators 16-23 |
| Data[0] | Actuators 24-31 |

### Example

To activate actuators corresponding to bits 0 and 31:

```text
CAN ID:  0x0C8
DLC:     4
DATA:    80 00 00 01
```

```
cansend can0 0C8#80000001
```

Resulting actuator state:

```c
0x80000001
```

## Firmware Behavior

- Hardware CAN filtering accepts only standard CAN ID `200`.
- The board does not transmit CAN responses.
