package _My_device;

import com.pauware.pauware_engine._Core.*;
import com.pauware.pauware_engine._Exception.*;
import com.pauware.pauware_engine._Java_ME.*;

/**
 * Java ME style for illustration only:
 */
public class My_device implements Java_MEExecutor {

    /**
     * Business data
     */
    private Port _port = new Port();
    /**
     * UML state machine
     */
    AbstractStatechart _Idle;
    AbstractStatechart _S11;
    AbstractStatechart _S12;
    AbstractStatechart _S21;
    AbstractStatechart _S22;
    AbstractStatechart _S31;
    AbstractStatechart _S32;
    AbstractStatechart _S1;
    AbstractStatechart _S2;
    AbstractStatechart _S3;
    AbstractStatechart _Busy;
    AbstractStatechart_monitor _My_device_state_machine;

    private void init_structure() throws Statechart_exception {
    }

    private void init_behavior() throws Statechart_exception {
        _Idle = new Java_MEStatechart("Idle");
        _Idle.inputState();
        _Idle.stateInvariant(_port, "isClosed");
        _S11 = (new Java_MEStatechart("S11").set_entryAction(this, "w")).set_exitAction(this, "x");
        _S11.inputState();
        _S12 = (new Java_MEStatechart("S12")).set_entryAction(this, "y").set_exitAction(this, "z");
        _S21 = new Java_MEStatechart("S21");
        _S22 = new Java_MEStatechart("S22").set_entryAction(this, "request_h", null, AbstractStatechart.Reentrance);
        _S22.inputState();
        _S31 = new Java_MEStatechart("S31");
        _S32 = new Java_MEStatechart("S32");
        _S32.doActivity(_port, "listenTo");
        _S1 = (_S11.xor(_S12)).name("S1");
        _S2 = (_S21.xor(_S22)).name("S2");
        _S3 = _S31.and(_S32).name("S3");
        _Busy = (_S1.and(_S2)).and(_S3).name("Busy");
        _Busy.set_entryAction(_port, "setOpen", new Object[]{Boolean.valueOf(true)});
        _Busy.stateInvariant(_port, "isOpen");
        _My_device_state_machine = new Java_MEStatechart_monitor(_Idle.xor(_Busy), "My device", AbstractStatechart_monitor.Don_t_show_on_system_out);
    }

    public void start() throws Statechart_exception {
        _My_device_state_machine.fires("request_b", _S1, _S12);
        _My_device_state_machine.fires("request_c", _Busy, _S12);
        _My_device_state_machine.fires("request_c", _Busy, _S22);
        _My_device_state_machine.fires("request_d", _Busy, _S21);
        _My_device_state_machine.fires("request_e", _Busy, _Idle);
        _My_device_state_machine.fires("request_f", _S21, _Idle);
        _My_device_state_machine.fires("request_g", _S12, _S11);
        _My_device_state_machine.fires("request_h", _S31, _S31, true, this, "a");
        _My_device_state_machine.fires("go", _Idle, _Busy);
        // Transition below causes problem due to 'guard' returns 'true'
        // and thus conflicts with immediately prior transition:
        // _My_component_state_machine.fires("go",_Idle,_Busy,this,"guard");

        /*_My_component_state_machine.fires("go_with_error",_Idle,_S21);
         _My_component_state_machine.fires("go_with_error",_Idle,_S22);*/

        /*_My_component_state_machine.fires("go_somehow_weird",_Idle,_Busy);
         _My_component_state_machine.fires("go_somehow_weird",_Idle,_S21);*/

        /*_My_component_state_machine.fires("overriding_example",_Busy,_Idle);
         _My_component_state_machine.fires("overriding_example",_S2,_Idle);*/
        _My_device_state_machine.start();
    }

    public void stop() throws Statechart_exception {
        _My_device_state_machine.stop();
    }

    public My_device() throws Statechart_exception {
        init_structure();
        init_behavior();
    }

    /**
     * UML events
     */
    public void request_b() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_b");
    }

    public void request_c() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_c");
    }

    public void request_d() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_d");
    }

    public void request_e() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_e", AbstractStatechart_monitor.Compute_invariants);
    }

    public void request_f() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_f");
    }

    public void request_g() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_g");
    }

    public void request_h() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("request_h");
    }

    public void go() throws Statechart_exception {
        _My_device_state_machine.run_to_completion("go", AbstractStatechart_monitor.Compute_invariants);
    }

// For testing purposes only:
//    public void go_with_error() throws Statechart_exception {
//        _My_device_state_machine.run_to_completion("go_with_error");
//    }
//    public void go_somehow_weird() throws Statechart_exception {
//        _My_device_state_machine.run_to_completion("go_somehow_weird");
//    }
//    public void overriding_example() throws Statechart_exception {
//        _My_device_state_machine.run_to_completion("overriding_example");
//    }
    /**
     * UML actions
     */
    public void a() {
        System.out.println("\ta activated\n");
    }

    public void w() {
        System.out.println("\tw activated\n");
    }

    public void x() {
        System.out.println("\tx activated\n");
// For testing purposes only:
//        _port = null; // NullPointerException simulation to create problems...
//        _port.setOpen(Boolean.FALSE);
    }

    public void y() {
        System.out.println("\ty activated\n");
    }

    public void z() {
        System.out.println("\tz activated\n");
    }

    /**
     * UML guards
     */
// For testing purposes only:
//    public boolean guard() {
//        return true;
//    }
    /**
     * Management
     */
    public String async_current_state() {
        return _My_device_state_machine.async_current_state();
    }

    public String current_state() {
        return _My_device_state_machine.current_state();
    }

    public boolean in_state(String name) {
        return _My_device_state_machine.in_state(name);
    }

    public void to_state(String name) throws Statechart_exception {
        _My_device_state_machine.to_state(name);
    }

    public String name() {
        return _My_device_state_machine.name();
    }

    public String verbose() {
        return _My_device_state_machine.verbose();
    }

    /**
     * Java ME style for illustration only:
     */
    public Object execute(String action, Object[] args) throws Throwable {
        /**
         * UML actions
         */
        Object result = null;
        if (action != null && action.equals("a")) {
            a();
        }
        if (action != null && action.equals("request_h")) {
            request_h();
        }
        if (action != null && action.equals("w")) {
            w();
        }
        if (action != null && action.equals("x")) {
            x();
        }
        if (action != null && action.equals("y")) {
            y();
        }
        if (action != null && action.equals("z")) {
            z();
        }
        /**
         * UML guards
         */
// For testing purposes only:
//        if (action != null && action.equals("guard")) {
//            result = new Boolean(guard());
//        }
        return result;
    }
}
