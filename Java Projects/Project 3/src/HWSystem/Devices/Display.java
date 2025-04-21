package HWSystem.Devices;

/**
 * Abstract class representing a display device. All display devices must
 * implement methods to print data.
 */
public abstract class Display extends Device {

    /**
     * Retrieves the type of the device.
     *
     * @return The string "Display" indicating the device type.
     */
    @Override
    public String getDevType() {
        return "Display";
    }

    /**
     * Prints the given data on the display.
     *
     * @param data The data to be printed on the display.
     */
    public abstract void printData(String data);
}
