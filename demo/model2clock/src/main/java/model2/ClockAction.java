package model2;

import static com.opensymphony.xwork2.Action.SUCCESS;

public class ClockAction {
    private ClockModel clockModel;
    public String execute() {
        clockModel = new ClockModel() ;

        return SUCCESS;
    }
    public ClockModel getClockModel() {
        return clockModel;
    }
}
