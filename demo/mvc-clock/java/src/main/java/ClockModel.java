import java.time.LocalTime;

public class ClockModel {
  private int time;

  public void init() {
    LocalTime local = LocalTime.now();
    time = local.getHour() * 3600 + local.getMinute() * 60
           + local.getSecond();
  }
  public ClockModel() {
    init();
  }
  public int getHours() {
    int hour = time / 3600;
    if (hour >= 12) {
      hour %= 12;
    }
    return hour;
  }
  public int getMinutes() {
    return (time % 3600) / 60;
  }
  public int getSeconds() {
    return time % 60;
  }
  public void advance() {
    ++time;
  }
}