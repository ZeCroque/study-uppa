package _My_device;

/**
 * Java ME style for illustration only:
 */
public class Port implements com.pauware.pauware_engine._Java_ME.Java_MEExecutor {

    boolean _open = false;

    public boolean isOpen() {
        return _open;
    }

    public boolean isClosed() {
        return !_open;
    }

    public void setOpen(Boolean open) {
        _open = open.booleanValue();
    }

    public void listenTo() {
    }

    /**
     * Java ME style for illustration only:
     */
    public Object execute(String action, Object[] args) throws Throwable {
        Object result = null;
        if (action != null && action.equals("isOpen")) {
            result = new Boolean(isOpen());
        }
        if (action != null && action.equals("isClosed")) {
            result = new Boolean(isClosed());
        }
        if (action != null && action.equals("setOpen")) {
            setOpen((Boolean) args[0]);
        }
        if (action != null && action.equals("listenTo")) {
            listenTo();
        }
        return result;
    }
}
