package model2;

import java.util.Calendar;

public class ClockModel {
    private long hours, minutes, seconds;
    public long getHours() {
        return hours;
    }
    public long getMinutes() {
        return minutes;
    }
    public long getSeconds() {
        return seconds;
    }
    public ClockModel() {
        Calendar now = Calendar.getInstance();
        hours = now.get(Calendar.HOUR);
        minutes = now.get(Calendar.MINUTE);
        seconds = now.get(Calendar.SECOND);
    }
}
