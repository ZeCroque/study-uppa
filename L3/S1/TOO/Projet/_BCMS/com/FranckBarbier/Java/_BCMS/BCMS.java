package com.FranckBarbier.Java._BCMS;

import com.pauware.pauware_engine._Core.*;
import com.pauware.pauware_engine._Exception.*;
import com.pauware.pauware_engine._Java_EE.*;

final class Timeout_log {

    java.util.Date _when;
    long _how_long;
    String _why;

    Timeout_log(java.util.Date when, long how_long, String why) {
        _when = when;
        _how_long = how_long;
        _why = why;

    }
}

public class BCMS extends Timer_monitor {

    private java.util.LinkedList<Timeout_log> _timeout_log;
    // SCXML DATAMODEL
    private final long _negotiation_limit = 180000L; // 3 min.
    private int _number_of_fire_truck_required = 0;
    private int _number_of_police_vehicle_required = 0;
    private java.util.ArrayList<String> _fire_trucks_dispatched = new java.util.ArrayList<>();
    private java.util.ArrayList<String> _police_vehicles_dispatched = new java.util.ArrayList<>();
    private java.util.ArrayList<String> _fire_trucks_arrived = new java.util.ArrayList<>();
    private java.util.ArrayList<String> _police_vehicles_arrived = new java.util.ArrayList<>();
    // SCXML event fields
    private final static String _FSC_connection_request = "FSC connection request";
    private final static String _PSC_connection_request = "PSC connection request";
    private final static String _State_fire_truck_number = "state fire truck number";
    private final static String _State_police_vehicle_number = "state police vehicle number";
    private final static String _Route_for_fire_trucks = "route for fire trucks";
    private final static String _Route_for_police_vehicles = "route for police vehicles";
    private final static String _No_more_route_left = "no more route left";
    private final static String _FSC_agrees_about_fire_truck_route = "FSC agrees about fire truck route";
    private final static String _FSC_agrees_about_police_vehicle_route = "FSC agrees about police vehicle route";
    private final static String _FSC_disagrees_about_fire_truck_route = "FSC disagrees about fire truck route";
    private final static String _FSC_disagrees_about_police_vehicle_route = "FSC disagrees about police vehicle route";
    private final static String _Fire_truck_dispatched = "fire truck dispatched";
    private final static String _Police_vehicle_dispatched = "police vehicle dispatched";
    private final static String _Fire_truck_arrived = "fire truck arrived";
    private final static String _Police_vehicle_arrived = "police vehicle arrived";
    private final static String _Close = "close";
    private final static String _Timeout = "timeout";

    /**
     * Page 8 of requirements doc.:
     */
    private final static String _Fire_truck_breakdown = "fire truck breakdown";
    private final static String _Police_vehicle_breakdown = "police vehicle breakdown";
    private final static String _Fire_truck_blocked = "fire truck blocked";
    private final static String _Police_vehicle_blocked = "police vehicle blocked";
    private final static String _Crisis_is_more_severe = "crisis is more severe";
    private final static String _Crisis_is_less_severe = "crisis is less severe";
    /**
     * For transitions without 'external' events:
     */
    private final static String _Enough_fire_trucks_dispatched = "enough fire trucks dispatched";
    private final static String _Enough_police_vehicles_dispatched = "enough police vehicles dispatched";
    private final static String _Enough_fire_trucks_arrived = "enough fire trucks arrived";
    private final static String _Enough_police_vehicles_arrived = "enough police vehicles arrived";
    // SCXML state fields
    protected AbstractStatechart _Init;
    protected AbstractStatechart _FSC_connected;
    protected AbstractStatechart _PSC_connected;
    protected AbstractStatechart _Crisis_details_exchange;
    protected AbstractStatechart _Step_3_Coordination;
    protected AbstractStatechart _Number_of_fire_truck_defined;
    protected AbstractStatechart _Number_of_police_vehicle_defined;
    protected AbstractStatechart _Route_plan_development;

    protected AbstractStatechart _Steps_33a1_33a2_Negotiation;
    protected AbstractStatechart _Route_for_fire_trucks_development;
    protected AbstractStatechart _Route_for_fire_trucks_to_be_proposed;
    protected AbstractStatechart _Route_for_fire_trucks_fixed;
    protected AbstractStatechart _Route_for_fire_trucks_approved;
    protected AbstractStatechart _Route_for_police_vehicles_development;
    protected AbstractStatechart _Route_for_police_vehicles_to_be_proposed;
    protected AbstractStatechart _Route_for_police_vehicles_fixed;
    protected AbstractStatechart _Route_for_police_vehicles_approved;
    /**
     * The state machine is adapted because of PlantUML limitations:
     */
    protected AbstractStatechart _End_of_route_for_fire_trucks_development;
    protected AbstractStatechart _End_of_route_for_police_vehicles_development;
    /**
     * End of PlantUML limitations
     */

    protected AbstractStatechart _Step_4_Dispatching;
    protected AbstractStatechart _All_fire_trucks_dispatched;
    protected AbstractStatechart _All_police_vehicles_dispatched;

    protected AbstractStatechart _Step_5_Arrival;
    protected AbstractStatechart _Fire_trucks_arriving;
    protected AbstractStatechart _All_fire_trucks_arrived;
    /**
     * The state machine is adapted because of PlantUML limitations:
     */
    protected AbstractStatechart _End_of_fire_trucks_arrival;
    /**
     * End of PlantUML limitations
     */
    protected AbstractStatechart _Fire_trucks_arrival;

    protected AbstractStatechart _Police_vehicles_arriving;
    protected AbstractStatechart _All_police_vehicles_arrived;
    /**
     * The state machine is adapted because of PlantUML limitations:
     */
    protected AbstractStatechart _End_of_police_vehicles_arrival;
    /**
     * End of PlantUML limitations
     */
    protected AbstractStatechart _Police_vehicles_arrival;

    protected AbstractStatechart _Completion_of_objectives;
    protected AbstractStatechart _End_of_crisis;
    protected AbstractStatechart_monitor _bCMS_state_machine;
    
// Statechart initialization:
    private void init_structure() throws Statechart_exception {
        _timeout_log = new java.util.LinkedList<>();
    }

    private void init_behavior() throws Statechart_exception {
        _Init = new Statechart("Init");
        _Init.inputState();
        _Init.set_entryAction(this, "clear");
        _FSC_connected = new Statechart("FSC connected");
        _PSC_connected = new Statechart("PSC connected");
        _Crisis_details_exchange = new Statechart("Crisis details exchange");
        _Crisis_details_exchange.set_entryAction(this, "to_be_killed"); // Timer must be killed because one may re-enter this state
        _Crisis_details_exchange.set_entryAction(this, "to_be_set", new Object[]{new Long(_negotiation_limit)});

        _Number_of_fire_truck_defined = new Statechart("Number of fire truck defined");
        _Number_of_police_vehicle_defined = new Statechart("Number of police vehicle defined");
        _Route_plan_development = new Statechart("Route plan development");

        _Route_for_fire_trucks_to_be_proposed = new Statechart("Route for fire trucks to_be_proposed");
        _Route_for_fire_trucks_to_be_proposed.inputState();
        _Route_for_fire_trucks_fixed = new Statechart("Route for fire trucks fixed");
        _Route_for_fire_trucks_approved = new Statechart("Route for fire trucks approved");
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        _End_of_route_for_fire_trucks_development = new Statechart("End of route for fire trucks development");
        _End_of_route_for_fire_trucks_development.outputState();
        /* suppression */ // _Route_for_fire_trucks_development = (_Route_for_fire_trucks_to_be_proposed.xor(_Route_for_fire_trucks_fixed.xor(_Route_for_fire_trucks_approved))).name("Route for fire trucks development");
        /* replacement */ _Route_for_fire_trucks_development = (_Route_for_fire_trucks_to_be_proposed.xor(_Route_for_fire_trucks_fixed.xor(_Route_for_fire_trucks_approved).xor(_End_of_route_for_fire_trucks_development))).name("Route for fire trucks development");
        /**
         * End of PlantUML limitations
         */

        _Route_for_police_vehicles_to_be_proposed = new Statechart("Route for police vehicles to_be_proposed");
        _Route_for_police_vehicles_to_be_proposed.inputState();
        _Route_for_police_vehicles_fixed = new Statechart("Route for police vehicles fixed");
        _Route_for_police_vehicles_approved = new Statechart("Route for police vehicles approved");
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        _End_of_route_for_police_vehicles_development = new Statechart("End of route for police vehicles development");
        _End_of_route_for_police_vehicles_development.outputState();
        /* suppression */ // _Route_for_police_vehicles_development = (_Route_for_police_vehicles_to_be_proposed.xor(_Route_for_police_vehicles_fixed.xor(_Route_for_police_vehicles_approved))).name("Route for police vehicles development");
        /* replacement */ _Route_for_police_vehicles_development = (_Route_for_police_vehicles_to_be_proposed.xor(_Route_for_police_vehicles_fixed.xor(_Route_for_police_vehicles_approved).xor(_End_of_route_for_police_vehicles_development))).name("Route for police vehicles development");
        /**
         * End of PlantUML limitations
         */

        _Steps_33a1_33a2_Negotiation = (_Route_for_fire_trucks_development.and(_Route_for_police_vehicles_development)).name("Steps 33a1 33a2-Negotiation");

        _Step_3_Coordination = (_Steps_33a1_33a2_Negotiation.xor(_Route_plan_development).xor(_Number_of_police_vehicle_defined).xor(_Number_of_fire_truck_defined)).name("Step 3-Coordination");
        _Step_3_Coordination.set_exitAction(this, "to_be_killed");
        /**
         * This allowed event is registred with fake arguments so that it can be
         * displayed by PauWare view. It is overriden at runtime with
         * appropriate values:
         */
        _Step_3_Coordination.allowedEvent(_Timeout, this, "record_timeout_reason", new Object[]{new Long(0L), ""});
        /**
         * End of fake arguments
         */
        _Step_4_Dispatching = new Statechart("Step 4-Dispatching");
        _All_fire_trucks_dispatched = new Statechart("All fire trucks dispatched");
        _All_fire_trucks_dispatched.stateInvariant(this, "FT_dispatched_equal_to_FT_required");
        _All_police_vehicles_dispatched = new Statechart("All police vehicles dispatched");
        _All_police_vehicles_dispatched.stateInvariant(this, "PV_dispatched_equal_to_PV_required");

        _Fire_trucks_arriving = new Statechart("Fire trucks arriving");
        _Fire_trucks_arriving.inputState();
        _All_fire_trucks_arrived = new Statechart("All fire trucks arrived");
        _All_fire_trucks_arrived.stateInvariant(this, "FT_arrived_greater_or_equal_to_FT_dispatched");
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        _End_of_fire_trucks_arrival = new Statechart("End of fire trucks arrival");
        _End_of_fire_trucks_arrival.outputState();
        /* suppression */ // _Fire_trucks_arrival = (_Fire_trucks_arriving.xor(_All_fire_trucks_arrived)).name("Fire trucks arrival");
        /* replacement */ _Fire_trucks_arrival = (_Fire_trucks_arriving.xor(_All_fire_trucks_arrived).xor(_End_of_fire_trucks_arrival)).name("Fire trucks arrival");
        /**
         * End of PlantUML limitations
         */
        _Police_vehicles_arriving = new Statechart("Police vehicles arriving");
        _Police_vehicles_arriving.inputState();
        _All_police_vehicles_arrived = new Statechart("All police vehicles arrived");
        _All_police_vehicles_arrived.stateInvariant(this, "PV_arrived_greater_or_equal_to_PV_dispatched");
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        _End_of_police_vehicles_arrival = new Statechart("End of police vehicles arrival");
        _End_of_police_vehicles_arrival.outputState();
        /* suppression */ // _Police_vehicles_arrival = (_Police_vehicles_arriving.xor(_All_police_vehicles_arrived)).name("Police vehicles arrival");
        /* replacement */ _Police_vehicles_arrival = (_Police_vehicles_arriving.xor(_All_police_vehicles_arrived).xor(_End_of_police_vehicles_arrival)).name("Police vehicles arrival");
        /**
         * End of PlantUML limitations
         */

        _Step_5_Arrival = (_Fire_trucks_arrival.and(_Police_vehicles_arrival)).name("Step 5-Arrival");
        // Please keep order among these four allowed events:
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "fire_truck_recalled");
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "police_vehicle_recalled");
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "enough_fire_trucks_arrived", null, AbstractStatechart.Reentrance);
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "enough_police_vehicles_arrived", null, AbstractStatechart.Reentrance);
        /**
         * These two allowed events are registred with fake arguments so that
         * they can be displayed by PauWare view. They are overriden at runtime
         * with appropriate values:
         */
        _Step_5_Arrival.allowedEvent(_Fire_truck_breakdown, this, "fire_trucks_dispatched_remove", new Object[]{""});
        _Step_5_Arrival.allowedEvent(_Police_vehicle_breakdown, this, "police_vehicles_dispatched_remove", new Object[]{""});
        /**
         * End of fake arguments
         */

        _Completion_of_objectives = new Statechart("Completion of objectives");
        _End_of_crisis = new Statechart("End of crisis");
        _End_of_crisis.outputState();

        /*// PauWare view:
        com.pauware.pauware_view.PauWare_view pv = null;
        // PauWare view activated ('pv' as last argument of next constructor). Toggle comment on following line for disactivation:
        pv = new com.pauware.pauware_view.PauWare_view();

        // PauWare view activated (last argument):*/
        _bCMS_state_machine = new Statechart_monitor(_Init.xor(_FSC_connected).xor(_PSC_connected).xor(_Crisis_details_exchange).xor(_Step_3_Coordination).xor(_Step_4_Dispatching).xor(_All_fire_trucks_dispatched).xor(_All_police_vehicles_dispatched).xor(_Step_5_Arrival).xor(_Completion_of_objectives).xor(_End_of_crisis), this.getClass().getSimpleName(), AbstractStatechart_monitor.Show_on_system_out);//, pv);
    }

    public void start() throws Statechart_exception {
        _bCMS_state_machine.fires(_FSC_connection_request, _Init, _FSC_connected);
        _bCMS_state_machine.fires(_PSC_connection_request, _Init, _PSC_connected);
        _bCMS_state_machine.fires(_FSC_connection_request, _PSC_connected, _Crisis_details_exchange);
        _bCMS_state_machine.fires(_PSC_connection_request, _FSC_connected, _Crisis_details_exchange);
        /**
         * These four transitions are registred with fake arguments so that they
         * can be displayed by PauWare view. They are overriden at runtime with
         * appropriate values:
         */
        _bCMS_state_machine.fires(_State_fire_truck_number, _Crisis_details_exchange, _Number_of_fire_truck_defined, true, this, "set_number_of_fire_truck_required", new Object[]{0});
        _bCMS_state_machine.fires(_State_fire_truck_number, _Number_of_police_vehicle_defined, _Route_plan_development, true, this, "set_number_of_fire_truck_required", new Object[]{0});
        _bCMS_state_machine.fires(_State_police_vehicle_number, _Crisis_details_exchange, _Number_of_police_vehicle_defined, true, this, "set_number_of_police_vehicle_required", new Object[]{0});
        _bCMS_state_machine.fires(_State_police_vehicle_number, _Number_of_fire_truck_defined, _Route_plan_development, true, this, "set_number_of_police_vehicle_required", new Object[]{0});
        /**
         * End of fake arguments
         */
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        /* Modification: event is internally re-sent to move to the right state inside '_Route_for_fire_trucks_development': */
        _bCMS_state_machine.fires(_Route_for_fire_trucks, _Route_plan_development, _Steps_33a1_33a2_Negotiation, true, this, "route_for_fires_trucks", null, AbstractStatechart.Reentrance);
        /* Modification: event is internally re-sent to move to the right state inside '_Route_for_police_vehicles_development': */
        _bCMS_state_machine.fires(_Route_for_police_vehicles, _Route_plan_development, _Steps_33a1_33a2_Negotiation, true, this, "route_for_police_vehicles", null, AbstractStatechart.Reentrance);
        /**
         * End of PlantUML limitations
         */
        _bCMS_state_machine.fires(_Route_for_fire_trucks, _Route_for_fire_trucks_to_be_proposed, _Route_for_fire_trucks_fixed);
        _bCMS_state_machine.fires(_Route_for_police_vehicles, _Route_for_police_vehicles_to_be_proposed, _Route_for_police_vehicles_fixed);
        _bCMS_state_machine.fires(_FSC_disagrees_about_fire_truck_route, _Route_for_fire_trucks_fixed, _Route_for_fire_trucks_to_be_proposed);
        _bCMS_state_machine.fires(_FSC_disagrees_about_police_vehicle_route, _Route_for_police_vehicles_fixed, _Route_for_police_vehicles_to_be_proposed);
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        /* suppression */ // _bCMS_state_machine.fires(_FSC_agrees_about_fire_truck_route, _Route_for_fire_trucks_fixed, _Step_4_Dispatching, this, "in_Route_for_police_vehicles_approved");
        /* replacement */ _bCMS_state_machine.fires(_FSC_agrees_about_fire_truck_route, _Route_for_fire_trucks_fixed, _End_of_route_for_fire_trucks_development, this, "in_Route_for_police_vehicles_approved");
        _bCMS_state_machine.fires(_FSC_agrees_about_fire_truck_route, _Route_for_fire_trucks_fixed, _Route_for_fire_trucks_approved, this, "not_in_Route_for_police_vehicles_approved");
        /* suppression */ // _bCMS_state_machine.fires(_FSC_agrees_about_police_vehicle_route, _Route_for_police_vehicles_fixed, _Step_4_Dispatching, this, "in_Route_for_fire_trucks_approved");
        /* replacement */ _bCMS_state_machine.fires(_FSC_agrees_about_police_vehicle_route, _Route_for_police_vehicles_fixed, _End_of_route_for_police_vehicles_development, this, "in_Route_for_fire_trucks_approved");
        _bCMS_state_machine.fires(_FSC_agrees_about_police_vehicle_route, _Route_for_police_vehicles_fixed, _Route_for_police_vehicles_approved, this, "not_in_Route_for_fire_trucks_approved");
        /**
         * End of PlantUML limitations
         */
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        /* addition */ _bCMS_state_machine.fires(AbstractStatechart.Completion, _Step_3_Coordination, _Step_4_Dispatching);
        /**
         * End of PlantUML limitations
         */
        _bCMS_state_machine.fires(_No_more_route_left, _Steps_33a1_33a2_Negotiation, _Step_4_Dispatching);
        /**
         * These eight transitions are registred with fake arguments so that
         * they can be displayed by PauWare view. They are overriden at runtime
         * with appropriate values:
         */
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "fire_trucks_dispatched_add", new Object[]{""});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "fire_trucks_dispatched_add", new Object[]{""});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "police_vehicles_dispatched_add", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "police_vehicles_dispatched_add", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        /**
         * End of fake arguments
         */
        _bCMS_state_machine.fires(_Enough_fire_trucks_dispatched, _Step_4_Dispatching, _All_fire_trucks_dispatched, this, "fire_truck_dispatched_greater_than_or_equal_to_number_of_fire_truck_required");
        _bCMS_state_machine.fires(_Enough_fire_trucks_dispatched, _All_police_vehicles_dispatched, _Step_5_Arrival, this, "fire_truck_dispatched_greater_than_or_equal_to_number_of_fire_truck_required");

        _bCMS_state_machine.fires(_Enough_police_vehicles_dispatched, _Step_4_Dispatching, _All_police_vehicles_dispatched, this, "police_vehicle_dispatched_greater_than_or_equal_to_number_of_police_vehicle_required");
        _bCMS_state_machine.fires(_Enough_police_vehicles_dispatched, _All_fire_trucks_dispatched, _Step_5_Arrival, this, "police_vehicle_dispatched_greater_than_or_equal_to_number_of_police_vehicle_required");

        _bCMS_state_machine.fires(_Enough_fire_trucks_arrived, _Fire_trucks_arriving, _All_fire_trucks_arrived, this, "fire_truck_arrived_greater_than_or_equal_to_fire_truck_dispatched_and_not_in_All_police_vehicles_arrived");
        _bCMS_state_machine.fires(_Enough_police_vehicles_arrived, _Police_vehicles_arriving, _All_police_vehicles_arrived, this, "police_vehicle_arrived_greater_than_or_equal_to_police_vehicle_dispatched_and_not_in_All_fire_trucks_arrived");

        _bCMS_state_machine.fires(_Crisis_is_more_severe, _Step_5_Arrival, _Crisis_details_exchange);
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        /* suppression */ // _bCMS_state_machine.fires(_Enough_fire_trucks_arrived, _Fire_trucks_arriving, _Completion_of_objectives, this, "fire_truck_arrived_greater_than_or_equal_to_fire_truck_dispatched_and_in_All_police_vehicles_arrived");
        /* replacement */ _bCMS_state_machine.fires(_Enough_fire_trucks_arrived, _Fire_trucks_arriving, _End_of_fire_trucks_arrival, this, "fire_truck_arrived_greater_than_or_equal_to_fire_truck_dispatched_and_in_All_police_vehicles_arrived");
        /* suppression */ // _bCMS_state_machine.fires(_Enough_police_vehicles_arrived, _Police_vehicles_arriving, _Completion_of_objectives, this, "police_vehicle_arrived_greater_than_or_equal_to_police_vehicle_dispatched_and_in_All_fire_trucks_arrived");
        /* replacement */ _bCMS_state_machine.fires(_Enough_police_vehicles_arrived, _Police_vehicles_arriving, _End_of_police_vehicles_arrival, this, "police_vehicle_arrived_greater_than_or_equal_to_police_vehicle_dispatched_and_in_All_fire_trucks_arrived");
        /* addition */ _bCMS_state_machine.fires(AbstractStatechart.Completion, _Step_5_Arrival, _Completion_of_objectives);
        /**
         * End of PlantUML limitations
         */
        /**
         * These six transitions are registred with fake arguments so that they
         * can be displayed by PauWare view. They are overriden at runtime with
         * appropriate values:
         */
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving, this, "fire_truck_arrived_less_than_fire_truck_dispatched", null, this, "fire_trucks_arrived_add", new Object[]{""});
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving, this, "fire_truck_arrived_less_than_fire_truck_dispatched", null, this, "enough_fire_trucks_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving, this, "police_vehicle_arrived_less_than_police_vehicle_dispatched", null, this, "police_vehicles_arrived_add", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving, this, "police_vehicle_arrived_less_than_police_vehicle_dispatched", null, this, "enough_police_vehicles_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Fire_truck_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "fire_trucks_dispatched_remove", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "police_vehicles_dispatched_remove", new Object[]{""});
        /**
         * End of fake arguments
         */
        _bCMS_state_machine.fires(_Close, _Completion_of_objectives, _End_of_crisis);
        _bCMS_state_machine.start();
    }

    public void stop() throws Statechart_exception {
        _bCMS_state_machine.stop();
    }

    public BCMS() throws Statechart_exception {
        init_structure();
        init_behavior();
    }

// SCXML event methods:
    public void FSC_connection_request() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_FSC_connection_request);
    }

    public void PSC_connection_request() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_PSC_connection_request);
    }

    public void state_fire_truck_number(int number_of_fire_truck_required) throws Statechart_exception {
        _bCMS_state_machine.fires(_State_fire_truck_number, _Crisis_details_exchange, _Number_of_fire_truck_defined, true, this, "set_number_of_fire_truck_required", new Object[]{number_of_fire_truck_required});
        _bCMS_state_machine.fires(_State_fire_truck_number, _Number_of_police_vehicle_defined, _Route_plan_development, true, this, "set_number_of_fire_truck_required", new Object[]{number_of_fire_truck_required});
        _bCMS_state_machine.run_to_completion(_State_fire_truck_number);
    }

    public void state_police_vehicle_number(int number_of_police_vehicle_required) throws Statechart_exception {
        _bCMS_state_machine.fires(_State_police_vehicle_number, _Crisis_details_exchange, _Number_of_police_vehicle_defined, true, this, "set_number_of_police_vehicle_required", new Object[]{number_of_police_vehicle_required});
        _bCMS_state_machine.fires(_State_police_vehicle_number, _Number_of_fire_truck_defined, _Route_plan_development, true, this, "set_number_of_police_vehicle_required", new Object[]{number_of_police_vehicle_required});
        _bCMS_state_machine.run_to_completion(_State_police_vehicle_number);
    }

    public void route_for_fire_trucks() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Route_for_fire_trucks);
    }

    public void route_for_police_vehicles() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Route_for_police_vehicles);
    }

    public void no_more_route_left() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_No_more_route_left);
    }

    public void FSC_agrees_about_fire_truck_route() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_FSC_agrees_about_fire_truck_route);
    }

    public void FSC_agrees_about_police_vehicle_route() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_FSC_agrees_about_police_vehicle_route);
    }

    public void FSC_disagrees_about_fire_truck_route() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_FSC_disagrees_about_fire_truck_route);
    }

    public void FSC_disagrees_about_police_vehicle_route() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_FSC_disagrees_about_police_vehicle_route);
    }

    public void enough_fire_trucks_dispatched() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_fire_trucks_dispatched, AbstractStatechart_monitor.Compute_invariants);
    }

    public void fire_truck_dispatched(String fire_truck) throws Statechart_exception {
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "fire_trucks_dispatched_add", new Object[]{fire_truck});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "fire_trucks_dispatched_add", new Object[]{fire_truck});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Fire_truck_dispatched);
    }

    public void enough_police_vehicles_dispatched() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_police_vehicles_dispatched, AbstractStatechart_monitor.Compute_invariants);
    }

    public void police_vehicle_dispatched(String police_vehicle) throws Statechart_exception {
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "police_vehicles_dispatched_add", new Object[]{police_vehicle});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "police_vehicles_dispatched_add", new Object[]{police_vehicle});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Police_vehicle_dispatched);
    }

    public void enough_fire_trucks_arrived() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_fire_trucks_arrived, AbstractStatechart_monitor.Compute_invariants);
    }

    public void fire_truck_arrived(String fire_truck) throws Statechart_exception {
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving, this, "fire_truck_arrived_less_than_fire_truck_dispatched", null, this, "fire_trucks_arrived_add", new Object[]{fire_truck});
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving, this, "fire_truck_arrived_less_than_fire_truck_dispatched", null, this, "enough_fire_trucks_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Fire_truck_arrived);
    }

    public void enough_police_vehicles_arrived() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_police_vehicles_arrived, AbstractStatechart_monitor.Compute_invariants);
    }

    public void police_vehicle_arrived(String police_vehicle) throws Statechart_exception {
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving, this, "police_vehicle_arrived_less_than_police_vehicle_dispatched", null, this, "police_vehicles_arrived_add", new Object[]{police_vehicle});
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving, this, "police_vehicle_arrived_less_than_police_vehicle_dispatched", null, this, "enough_police_vehicles_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Police_vehicle_arrived);
    }

    @Override
    public void time_out(long delay, AbstractStatechart context) throws Statechart_exception {
        _Step_3_Coordination.allowedEvent(_Timeout, this, "record_timeout_reason", new Object[]{new Long(delay), _bCMS_state_machine.async_current_state()});
        _bCMS_state_machine.run_to_completion(_Timeout);
    }

    @Override
    public void time_out_error(Statechart_exception se) throws Statechart_exception {
        // possible fault recovery here...
    }

    public void fire_truck_breakdown(String fire_truck,/* may be 'null' */ String replacement_fire_truck) throws Statechart_exception {
        Object[] args;
        if (replacement_fire_truck != null) {
            args = new Object[]{fire_truck, replacement_fire_truck};
        } else {
            args = new Object[]{fire_truck};
        }
        _Step_5_Arrival.allowedEvent(_Fire_truck_breakdown, this, "fire_trucks_dispatched_remove", args);
        _bCMS_state_machine.run_to_completion(_Fire_truck_breakdown);
    }

    public void police_vehicle_breakdown(String police_vehicle,/* may be 'null' */ String replacement_police_vehicle) throws Statechart_exception {
        Object[] args;
        if (replacement_police_vehicle != null) {
            args = new Object[]{police_vehicle, replacement_police_vehicle};
        } else {
            args = new Object[]{police_vehicle};
        }
        _Step_5_Arrival.allowedEvent(_Police_vehicle_breakdown, this, "police_vehicles_dispatched_remove", args);
        _bCMS_state_machine.run_to_completion(_Police_vehicle_breakdown);
    }

    public void fire_truck_blocked(String fire_truck) throws Statechart_exception {
        _bCMS_state_machine.fires(_Fire_truck_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "fire_trucks_dispatched_remove", new Object[]{fire_truck});
        _bCMS_state_machine.run_to_completion(_Fire_truck_blocked);
    }

    public void police_vehicle_blocked(String police_vehicle) throws Statechart_exception {
        _bCMS_state_machine.fires(_Police_vehicle_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "police_vehicles_dispatched_remove", new Object[]{police_vehicle});
        _bCMS_state_machine.run_to_completion(_Police_vehicle_blocked);
    }

    public void crisis_is_more_severe() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Crisis_is_more_severe);
    }

    public void crisis_is_less_severe() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Crisis_is_less_severe);
    }

    public void close() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Close);
    }

    /**
     * SCXML conditions
     */
    public boolean in_Route_for_fire_trucks_approved() throws Statechart_exception {
        return _bCMS_state_machine.in_state(_Route_for_fire_trucks_approved.name());
    }

    public boolean not_in_Route_for_fire_trucks_approved() throws Statechart_exception {
        return !_bCMS_state_machine.in_state(_Route_for_fire_trucks_approved.name());
    }

    public boolean in_Route_for_police_vehicles_approved() throws Statechart_exception {
        return _bCMS_state_machine.in_state(_Route_for_police_vehicles_approved.name());
    }

    public boolean not_in_Route_for_police_vehicles_approved() throws Statechart_exception {
        return !_bCMS_state_machine.in_state(_Route_for_police_vehicles_approved.name());
    }

    public boolean fire_truck_dispatched_less_than_number_of_fire_truck_required() {
        return _fire_trucks_dispatched.size() < _number_of_fire_truck_required;
    }

    public boolean fire_truck_dispatched_greater_than_or_equal_to_number_of_fire_truck_required() {
        return _fire_trucks_dispatched.size() >= _number_of_fire_truck_required;
    }

    public boolean police_vehicle_dispatched_less_than_number_of_police_vehicle_required() {
        return _police_vehicles_dispatched.size() < _number_of_police_vehicle_required;
    }

    public boolean police_vehicle_dispatched_greater_than_or_equal_to_number_of_police_vehicle_required() {
        return _police_vehicles_dispatched.size() >= _number_of_police_vehicle_required;
    }

    public boolean fire_truck_arrived_less_than_fire_truck_dispatched() {
        return _fire_trucks_arrived.size() < _fire_trucks_dispatched.size();
    }

    public boolean fire_truck_arrived_greater_than_or_equal_to_fire_truck_dispatched_and_in_All_police_vehicles_arrived() {
        return _fire_trucks_arrived.size() >= _fire_trucks_dispatched.size() && _All_police_vehicles_arrived.active();
    }

    public boolean fire_truck_arrived_greater_than_or_equal_to_fire_truck_dispatched_and_not_in_All_police_vehicles_arrived() {
        return _fire_trucks_arrived.size() >= _fire_trucks_dispatched.size() && !_All_police_vehicles_arrived.active();
    }

    public boolean police_vehicle_arrived_less_than_police_vehicle_dispatched() {
        return _police_vehicles_arrived.size() < _police_vehicles_dispatched.size();
    }

    public boolean police_vehicle_arrived_greater_than_or_equal_to_police_vehicle_dispatched_and_in_All_fire_trucks_arrived() {
        return _police_vehicles_arrived.size() >= _police_vehicles_dispatched.size() && _All_fire_trucks_arrived.active();
    }

    public boolean police_vehicle_arrived_greater_than_or_equal_to_police_vehicle_dispatched_and_not_in_All_fire_trucks_arrived() {
        return _police_vehicles_arrived.size() >= _police_vehicles_dispatched.size() && !_All_fire_trucks_arrived.active();
    }

    /**
     * SCXML actions
     */
    public void record_timeout_reason(Long delay, String reason) {
        _timeout_log.add(new Timeout_log(new java.util.Date(), delay, reason));
    }

    public void set_number_of_fire_truck_required(Integer number_of_fire_truck_required) {
        _number_of_fire_truck_required = number_of_fire_truck_required;
    }

    public void set_number_of_police_vehicle_required(Integer number_of_police_vehicle_required) {
        _number_of_police_vehicle_required = number_of_police_vehicle_required;
    }

    public void fire_trucks_dispatched_add(String fire_truck) {
        _fire_trucks_dispatched.add(fire_truck);
    }

    public void police_vehicles_dispatched_add(String police_vehicle) {
        _police_vehicles_dispatched.add(police_vehicle);
    }

    public void fire_trucks_arrived_add(String fire_truck) {
        if (_fire_trucks_dispatched.contains(fire_truck)) {
            _fire_trucks_arrived.add(fire_truck);
        }
    }

    public void police_vehicles_arrived_add(String police_vehicle) {
        if (_police_vehicles_dispatched.contains(police_vehicle)) {
            _police_vehicles_arrived.add(police_vehicle);
        }
    }

    public boolean fire_trucks_dispatched_remove(String fire_truck) {
        return _fire_trucks_dispatched.remove(fire_truck);
    }

    public void fire_trucks_dispatched_remove(String fire_truck, String replacement_fire_truck) {
        if (_fire_trucks_dispatched.remove(fire_truck)) {
            if (replacement_fire_truck != null) {
                _fire_trucks_dispatched.add(replacement_fire_truck);
            }
        }
    }

    public boolean police_vehicles_dispatched_remove(String police_vehicle) {
        return _police_vehicles_dispatched.remove(police_vehicle);
    }

    public void police_vehicles_dispatched_remove(String police_vehicle, String replacement_police_vehicle) {
        if (_police_vehicles_dispatched.remove(police_vehicle)) {
            if (replacement_police_vehicle != null) {
                _police_vehicles_dispatched.add(replacement_police_vehicle);
            }
        }
    }

    public boolean fire_truck_recalled() {
        boolean recalled = false;
        for (String fire_truck : _fire_trucks_dispatched) {
            if (!_fire_trucks_arrived.contains(fire_truck)) {
                _fire_trucks_dispatched.remove(fire_truck);
                recalled = true;
                break;
            }
        }
        if (!recalled && !_fire_trucks_dispatched.isEmpty()) {
            _fire_trucks_dispatched.remove((new java.util.Random()).nextInt(_fire_trucks_dispatched.size()));
            recalled = true;
        }
        return recalled;
    }

    public boolean police_vehicle_recalled() {
        boolean recalled = false;
        for (String fire_truck : _police_vehicles_dispatched) {
            if (!_police_vehicles_dispatched.contains(fire_truck)) {
                _police_vehicles_dispatched.remove(fire_truck);
                recalled = true;
                break;
            }
        }
        if (!recalled && !_police_vehicles_dispatched.isEmpty()) {
            _police_vehicles_dispatched.remove((new java.util.Random()).nextInt(_police_vehicles_dispatched.size()));
            recalled = true;
        }
        return recalled;
    }

    /**
     * Invariants
     */
    public boolean FT_dispatched_equal_to_FT_required() {
        return _number_of_fire_truck_required == _fire_trucks_dispatched.size();
    }

    public boolean PV_dispatched_equal_to_PV_required() {
        return _number_of_police_vehicle_required == _police_vehicles_dispatched.size();
    }

    public boolean FT_arrived_greater_or_equal_to_FT_dispatched() {
        return _fire_trucks_dispatched.size() <= _fire_trucks_arrived.size();
    }

    public boolean PV_arrived_greater_or_equal_to_PV_dispatched() {
        return _police_vehicles_dispatched.size() <= _police_vehicles_arrived.size();
    }

    public void clear() {
        _number_of_fire_truck_required = 0;
        _number_of_police_vehicle_required = 0;
        _fire_trucks_dispatched.clear();
        _police_vehicles_dispatched.clear();
        _fire_trucks_arrived.clear();
        _police_vehicles_arrived.clear();
    }

    public void reset() throws Statechart_exception {
        _bCMS_state_machine.to_state(_Init.name());
    }

    
}
