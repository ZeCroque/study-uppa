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

// For the sake of simplicity, an embedded database is used...
    static {
        try {
            java.sql.DriverManager.registerDriver(new org.apache.derby.jdbc.EmbeddedDriver());
        } catch (java.sql.SQLException sqle0) {
            System.err.println(BCMS.class.getSimpleName() + " database driver? " + sqle0.getMessage());
            System.exit(-1); // No way!
        }
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database;create=true")) {
            java.sql.Statement statement = connection.createStatement();
            statement.execute("CREATE TABLE Crisis(\n"
                    + "crisis_id INT not null GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1),\n"
                    + "fire_truck_number integer,\n"
                    + "police_truck_number integer,\n"
                    + "constraint Crisis_key primary key(crisis_id))");
            statement.execute("CREATE TABLE Fire_truck(\n"
                    + "fire_truck_name varchar(30),\n"
                    + "constraint Fire_truck_key primary key(fire_truck_name))");
            statement.execute("INSERT INTO Fire_truck VALUES('Fire truck #1')");
            statement.execute("INSERT INTO Fire_truck VALUES('Fire truck #2')");
            statement.execute("INSERT INTO Fire_truck VALUES('Fire truck #3')");
            statement.execute("INSERT INTO Fire_truck VALUES('Fire truck #4')");
            statement.execute("CREATE TABLE Police_vehicle(\n"
                    + "police_vehicle_name varchar(30),\n"
                    + "constraint Police_vehicle_key primary key(police_vehicle_name))");
            statement.execute("INSERT INTO Police_vehicle VALUES('Police vehicle #1')");
            statement.execute("INSERT INTO Police_vehicle VALUES('Police vehicle #2')");
            statement.execute("INSERT INTO Police_vehicle VALUES('Police vehicle #3')");
            statement.execute("CREATE TABLE Route(\n"
                    + "route_name varchar(30),\n"
                    + "constraint Route_key primary key(route_name))");
            statement.execute("INSERT INTO Route VALUES('Route #1')");
            statement.execute("INSERT INTO Route VALUES('Route #2')");
            statement.execute("INSERT INTO Route VALUES('Route #3')");
            statement.execute("CREATE TABLE Crisis_Fire_truck(\n"
                    + "crisis_id INT,\n"
                    + "fire_truck_name varchar(30),\n"
                    + "fire_truck_status varchar(10) CONSTRAINT fire_truck_status_check CHECK (fire_truck_status IN ('" + Status.Dispatched + "','" + Status.Arrived + "','" + Status.Blocked + "','" + Status.Breakdown + "')),\n"
                    + "constraint Crisis_Fire_truck_key primary key(crisis_id,fire_truck_name),\n"
                    + "constraint Crisis_foreign_key2 foreign key(crisis_id) references Crisis(crisis_id) on delete cascade,\n"
                    + "constraint Fire_truck_foreign_key foreign key(fire_truck_name) references Fire_truck(fire_truck_name) on delete cascade)");
            statement.execute("CREATE TABLE Crisis_Police_vehicle(\n"
                    + "crisis_id INT,\n"
                    + "police_vehicle_name varchar(30),\n"
                    + "police_vehicle_status varchar(10) CONSTRAINT police_vehicle_status_check CHECK (police_vehicle_status IN ('" + Status.Dispatched + "','" + Status.Arrived + "','" + Status.Blocked + "','" + Status.Breakdown + "')),\n"
                    + "constraint Crisis_Police_vehicle_key primary key(crisis_id,police_vehicle_name),\n"
                    + "constraint Crisis_foreign_key3 foreign key(crisis_id) references Crisis(crisis_id) on delete cascade,\n"
                    + "constraint Police_vehicle_foreign_key foreign key(police_vehicle_name) references Police_vehicle(police_vehicle_name) on delete cascade)");
        } catch (java.sql.SQLException sqle1) {
            System.err.println(BCMS.class.getSimpleName() + " database probably already exists? " + sqle1.getMessage());
            try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
                connection.createStatement().execute("DELETE FROM Crisis"); // 'on delete cascade'
            } catch (java.sql.SQLException sqle2) {
                System.err.println(BCMS.class.getSimpleName() + " database persistent error: " + sqle2.getMessage());
                System.exit(-1);
            }
        }
    }

    public enum Status {
        Dispatched, Arrived, Blocked, Breakdown
    };

    private int _crisis_id = -1;
    private java.util.LinkedList<Timeout_log> _timeout_log;
    // SCXML DATAMODEL
    private final long _negotiation_limit = 180000L; // 3 min.
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
         * This allowed event is registered with fake arguments so that it can
         * be displayed by PauWare view. It is overridden at runtime with
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
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "recall_fire_truck");
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "recall_police_vehicle");
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "enough_fire_trucks_arrived", null, AbstractStatechart.Reentrance);
        _Step_5_Arrival.allowedEvent(_Crisis_is_less_severe, this, "enough_police_vehicles_arrived", null, AbstractStatechart.Reentrance);
        /**
         * These two allowed events are registered with fake arguments so that
         * they can be displayed by PauWare view. They are overridden at runtime
         * with appropriate values:
         */
        _Step_5_Arrival.allowedEvent(_Fire_truck_breakdown, this, "breakdown_fire_truck", new Object[]{"", ""});
        _Step_5_Arrival.allowedEvent(_Police_vehicle_breakdown, this, "breakdown_police_vehicle", new Object[]{"", ""});
        /**
         * End of fake arguments
         */

        _Completion_of_objectives = new Statechart("Completion of objectives");
        _End_of_crisis = new Statechart("End of crisis");
        _End_of_crisis.outputState();

        // PauWare view:
//        com.pauware.pauware_view.PauWare_view pv = null;
        // PauWare view activated ('pv' as last argument of next constructor). Toggle comment on following line for disactivation:
//        pv = new com.pauware.pauware_view.PauWare_view();
        // PauWare view activated (last argument):
        _bCMS_state_machine = new Statechart_monitor(_Init.xor(_FSC_connected).xor(_PSC_connected).xor(_Crisis_details_exchange).xor(_Step_3_Coordination).xor(_Step_4_Dispatching).xor(_All_fire_trucks_dispatched).xor(_All_police_vehicles_dispatched).xor(_Step_5_Arrival).xor(_Completion_of_objectives).xor(_End_of_crisis), this.getClass().getSimpleName(), AbstractStatechart_monitor.Show_on_system_out/*, pv*/);
    }

    public void start() throws Statechart_exception {
        _bCMS_state_machine.fires(_FSC_connection_request, _Init, _FSC_connected);
        _bCMS_state_machine.fires(_PSC_connection_request, _Init, _PSC_connected);
        _bCMS_state_machine.fires(_FSC_connection_request, _PSC_connected, _Crisis_details_exchange);
        _bCMS_state_machine.fires(_PSC_connection_request, _FSC_connected, _Crisis_details_exchange);
        /**
         * These four transitions are registered with fake arguments so that
         * they can be displayed by PauWare view. They are overridden at runtime
         * with appropriate values:
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
         * These eight transitions are registered with fake arguments so that
         * they can be displayed by PauWare view. They are overridden at runtime
         * with appropriate values:
         */
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "dispatch_fire_truck", new Object[]{""});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "dispatch_fire_truck", new Object[]{""});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "dispatch_police_vehicle", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "dispatch_police_vehicle", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        /**
         * End of fake arguments
         */
        _bCMS_state_machine.fires(_Enough_fire_trucks_dispatched, _Step_4_Dispatching, _All_fire_trucks_dispatched, this, "fire_truck_dispatched_greater_than_or_equal_to_number_of_fire_truck_required");
        _bCMS_state_machine.fires(_Enough_fire_trucks_dispatched, _All_police_vehicles_dispatched, _Step_5_Arrival, this, "fire_truck_dispatched_greater_than_or_equal_to_number_of_fire_truck_required");

        _bCMS_state_machine.fires(_Enough_police_vehicles_dispatched, _Step_4_Dispatching, _All_police_vehicles_dispatched, this, "police_vehicle_dispatched_greater_than_or_equal_to_number_of_police_vehicle_required");
        _bCMS_state_machine.fires(_Enough_police_vehicles_dispatched, _All_fire_trucks_dispatched, _Step_5_Arrival, this, "police_vehicle_dispatched_greater_than_or_equal_to_number_of_police_vehicle_required");

        _bCMS_state_machine.fires(_Enough_fire_trucks_arrived, _Fire_trucks_arriving, _All_fire_trucks_arrived, this, "no_more_dispatched_fire_trucks_and_not_in_All_police_vehicles_arrived");
        _bCMS_state_machine.fires(_Enough_police_vehicles_arrived, _Police_vehicles_arriving, _All_police_vehicles_arrived, this, "no_more_dispatched_police_vehicles_and_not_in_All_fire_trucks_arrived");

        _bCMS_state_machine.fires(_Crisis_is_more_severe, _Step_5_Arrival, _Crisis_details_exchange);
        /**
         * The state machine is adapted because of PlantUML limitations:
         */
        /* suppression */ // _bCMS_state_machine.fires(_Enough_fire_trucks_arrived, _Fire_trucks_arriving, _Completion_of_objectives, this, "no_more_dispatched_fire_trucks_and_in_All_police_vehicles_arrived");
        /* replacement */ _bCMS_state_machine.fires(_Enough_fire_trucks_arrived, _Fire_trucks_arriving, _End_of_fire_trucks_arrival, this, "no_more_dispatched_fire_trucks_and_in_All_police_vehicles_arrived");
        /* suppression */ // _bCMS_state_machine.fires(_Enough_police_vehicles_arrived, _Police_vehicles_arriving, _Completion_of_objectives, this, "no_more_dispatched_police_vehicles_and_in_All_fire_trucks_arrived");
        /* replacement */ _bCMS_state_machine.fires(_Enough_police_vehicles_arrived, _Police_vehicles_arriving, _End_of_police_vehicles_arrival, this, "no_more_dispatched_police_vehicles_and_in_All_fire_trucks_arrived");
        /* addition */ _bCMS_state_machine.fires(AbstractStatechart.Completion, _Step_5_Arrival, _Completion_of_objectives);
        /**
         * End of PlantUML limitations
         */
        /**
         * These six transitions are registered with fake arguments so that they
         * can be displayed by PauWare view. They are overridden at runtime with
         * appropriate values:
         */
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving/*, this, "X", null*/, true, this, "arrive_fire_truck", new Object[]{""});
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving/*, this, "X", null*/, true, this, "enough_fire_trucks_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving,/* this, "Y", null*/ true, this, "arrive_police_vehicle", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving,/* this, "Y", null*/ true, this, "enough_police_vehicles_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Fire_truck_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "block_fire_truck", new Object[]{""});
        _bCMS_state_machine.fires(_Police_vehicle_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "block_police_vehicle", new Object[]{""});
        /**
         * End of fake arguments
         */
        _bCMS_state_machine.fires(_Close, _Completion_of_objectives, _End_of_crisis);

        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("INSERT INTO Crisis (fire_truck_number,police_truck_number) VALUES(0,0)");
            // Last (current) crisis:
            java.sql.ResultSet rs = connection.createStatement().executeQuery("SELECT MAX(crisis_id) FROM Crisis");
            if (rs.next()) {
                _crisis_id = rs.getInt(1);
            }
            assert (_crisis_id != -1);
        } catch (java.sql.SQLException sqle) {
            throw new Statechart_exception(sqle.getMessage() + ": " + sqle.getSQLState());
        }
        _bCMS_state_machine.start();
    }

    public void stop() throws Statechart_exception {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().execute("DELETE FROM Crisis WHERE crisis_id = " + _crisis_id);
        } catch (java.sql.SQLException sqle) {
            throw new Statechart_exception(sqle.getMessage() + ": " + sqle.getSQLState());
        }
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
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "dispatch_fire_truck", new Object[]{fire_truck});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "dispatch_fire_truck", new Object[]{fire_truck});
        _bCMS_state_machine.fires(_Fire_truck_dispatched, _All_police_vehicles_dispatched, _All_police_vehicles_dispatched, this, "fire_truck_dispatched_less_than_number_of_fire_truck_required", null, this, "enough_fire_trucks_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Fire_truck_dispatched);
    }

    public void enough_police_vehicles_dispatched() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_police_vehicles_dispatched, AbstractStatechart_monitor.Compute_invariants);
    }

    public void police_vehicle_dispatched(String police_vehicle) throws Statechart_exception {
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "dispatch_police_vehicle", new Object[]{police_vehicle});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _Step_4_Dispatching, _Step_4_Dispatching, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "dispatch_police_vehicle", new Object[]{police_vehicle});
        _bCMS_state_machine.fires(_Police_vehicle_dispatched, _All_fire_trucks_dispatched, _All_fire_trucks_dispatched, this, "police_vehicle_dispatched_less_than_number_of_police_vehicle_required", null, this, "enough_police_vehicles_dispatched", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Police_vehicle_dispatched);
    }

    public void enough_fire_trucks_arrived() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_fire_trucks_arrived, AbstractStatechart_monitor.Compute_invariants);
    }

    public void fire_truck_arrived(String fire_truck) throws Statechart_exception {
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving/*, this, "X", null*/, true, this, "arrive_fire_truck", new Object[]{fire_truck});
        _bCMS_state_machine.fires(_Fire_truck_arrived, _Fire_trucks_arriving, _Fire_trucks_arriving/*, this, "X", null*/, true, this, "enough_fire_trucks_arrived", null, AbstractStatechart.Reentrance);
        _bCMS_state_machine.run_to_completion(_Fire_truck_arrived);
    }

    public void enough_police_vehicles_arrived() throws Statechart_exception {
        _bCMS_state_machine.run_to_completion(_Enough_police_vehicles_arrived, AbstractStatechart_monitor.Compute_invariants);
    }

    public void police_vehicle_arrived(String police_vehicle) throws Statechart_exception {
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving,/* this, "Y", null*/ true, this, "arrive_police_vehicle", new Object[]{police_vehicle});
        _bCMS_state_machine.fires(_Police_vehicle_arrived, _Police_vehicles_arriving, _Police_vehicles_arriving,/* this, "Y", null*/ true, this, "enough_police_vehicles_arrived", null, AbstractStatechart.Reentrance);
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

    public void fire_truck_breakdown(String fire_truck,/* may be "" */ String replacement_fire_truck) throws Statechart_exception {
        Object[] args = new Object[]{fire_truck, replacement_fire_truck};
        _Step_5_Arrival.allowedEvent(_Fire_truck_breakdown, this, "breakdown_fire_truck", args);
        _bCMS_state_machine.run_to_completion(_Fire_truck_breakdown);
    }

    public void police_vehicle_breakdown(String police_vehicle,/* may be "" */ String replacement_police_vehicle) throws Statechart_exception {
        Object[] args = new Object[]{police_vehicle, replacement_police_vehicle};
        _Step_5_Arrival.allowedEvent(_Police_vehicle_breakdown, this, "breakdown_police_vehicle", args);
        _bCMS_state_machine.run_to_completion(_Police_vehicle_breakdown);
    }

    public void fire_truck_blocked(String fire_truck) throws Statechart_exception {
        _bCMS_state_machine.fires(_Fire_truck_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "block_fire_truck", new Object[]{fire_truck});
        _bCMS_state_machine.run_to_completion(_Fire_truck_blocked);
    }

    public void police_vehicle_blocked(String police_vehicle) throws Statechart_exception {
        _bCMS_state_machine.fires(_Police_vehicle_blocked, _Step_5_Arrival, _Crisis_details_exchange, true, this, "block_police_vehicle", new Object[]{police_vehicle});
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

    public boolean fire_truck_dispatched_less_than_number_of_fire_truck_required() throws java.sql.SQLException {
        return get_fire_trucks(Status.Dispatched).size() < get_number_of_fire_truck_required();
    }

    public boolean fire_truck_dispatched_greater_than_or_equal_to_number_of_fire_truck_required() throws java.sql.SQLException {
        return get_fire_trucks(Status.Dispatched).size() >= get_number_of_fire_truck_required();
    }

    public boolean police_vehicle_dispatched_less_than_number_of_police_vehicle_required() throws java.sql.SQLException {
        return get_police_vehicles(Status.Dispatched).size() < get_number_of_police_vehicle_required();
    }

    public boolean police_vehicle_dispatched_greater_than_or_equal_to_number_of_police_vehicle_required() throws java.sql.SQLException {
        return get_police_vehicles(Status.Dispatched).size() >= get_number_of_police_vehicle_required();
    }

//    public boolean X() throws java.sql.SQLException {
//        return true;
//    }
    public boolean no_more_dispatched_fire_trucks_and_in_All_police_vehicles_arrived() throws java.sql.SQLException {
        return get_fire_trucks(Status.Dispatched).isEmpty() && _All_police_vehicles_arrived.active();
    }

    public boolean no_more_dispatched_fire_trucks_and_not_in_All_police_vehicles_arrived() throws java.sql.SQLException {
        return get_fire_trucks(Status.Dispatched).isEmpty() && !_All_police_vehicles_arrived.active();
    }

//    public boolean Y() throws java.sql.SQLException {
//        return true;
//    }
    public boolean no_more_dispatched_police_vehicles_and_in_All_fire_trucks_arrived() throws java.sql.SQLException {
        return get_police_vehicles(Status.Dispatched).isEmpty() && _All_fire_trucks_arrived.active();
    }

    public boolean no_more_dispatched_police_vehicles_and_not_in_All_fire_trucks_arrived() throws java.sql.SQLException {
        return get_police_vehicles(Status.Dispatched).isEmpty() && !_All_fire_trucks_arrived.active();
    }

    /**
     * SCXML actions
     */
    public void arrive_fire_truck(String fire_truck_name) throws java.sql.SQLException {
        assert (get_fire_trucks(Status.Dispatched).contains(fire_truck_name));
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis_Fire_truck SET fire_truck_status = '" + Status.Arrived + "' WHERE fire_truck_name = " + '\'' + fire_truck_name + "' AND crisis_id = " + _crisis_id);
        }
    }

    public void arrive_police_vehicle(String police_vehicle_name) throws java.sql.SQLException {
        assert (get_police_vehicles(Status.Dispatched).contains(police_vehicle_name));
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis_Police_vehicle SET police_vehicle_status = '" + Status.Arrived + "' WHERE police_vehicle_name = " + '\'' + police_vehicle_name + "' AND crisis_id = " + _crisis_id);
        }
    }

    public void block_fire_truck(String fire_truck_name) throws java.sql.SQLException {
        assert (get_fire_trucks(Status.Arrived).contains(fire_truck_name));
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis_Fire_truck SET fire_truck_status = '" + Status.Blocked + "' WHERE fire_truck_name = " + '\'' + fire_truck_name + "' AND crisis_id = " + _crisis_id);
        }
    }

    public void block_police_vehicle(String police_vehicle_name) throws java.sql.SQLException {
        assert (get_police_vehicles(Status.Arrived).contains(police_vehicle_name));
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis_Police_vehicle SET police_vehicle_status = '" + Status.Blocked + "' WHERE police_vehicle_name = " + '\'' + police_vehicle_name + "' AND crisis_id = " + _crisis_id);
        }
    }

    public void breakdown_fire_truck(String fire_truck_name, String replacement_fire_truck_name) throws java.sql.SQLException {
        assert (get_fire_trucks(Status.Dispatched).contains(fire_truck_name) || get_fire_trucks(Status.Arrived).contains(fire_truck_name));
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis_Fire_truck SET fire_truck_status = '" + Status.Breakdown + "' WHERE fire_truck_name = " + '\'' + fire_truck_name + "' AND crisis_id = " + _crisis_id);
            if (replacement_fire_truck_name != null && !replacement_fire_truck_name.isEmpty()) {
                dispatch_fire_truck(replacement_fire_truck_name.toString());
            }
        }
    }

    public void breakdown_police_vehicle(String police_vehicle_name, String replacement_police_vehicle_name) throws java.sql.SQLException {
        assert (get_police_vehicles(Status.Dispatched).contains(police_vehicle_name) || get_police_vehicles(Status.Arrived).contains(police_vehicle_name));
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis_Police_vehicle SET police_vehicle_status = '" + Status.Breakdown + "' WHERE police_vehicle_name = " + '\'' + police_vehicle_name + "' AND crisis_id = " + _crisis_id);
            if (replacement_police_vehicle_name != null && !replacement_police_vehicle_name.isEmpty()) {
                dispatch_police_vehicle(replacement_police_vehicle_name.toString());
            }
        }
    }

    public void dispatch_fire_truck(String fire_truck_name) throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("INSERT INTO Crisis_Fire_truck VALUES(" + _crisis_id + ",'" + fire_truck_name + "'," + "'Dispatched')");
        }
    }

    public void dispatch_police_vehicle(String police_vehicle_name) throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("INSERT INTO Crisis_Police_vehicle VALUES(" + _crisis_id + ",'" + police_vehicle_name + "'," + "'Dispatched')");
        }
    }

    public boolean recall_fire_truck() throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.util.List<String> ft = get_fire_trucks(Status.Dispatched);
            if (!ft.isEmpty()) {
                connection.createStatement().execute("DELETE FROM Crisis_Fire_truck WHERE crisis_id = " + _crisis_id + " AND fire_truck_name = '" + ft.get(0) + "'");
                return true;
            }
            ft = get_fire_trucks(Status.Arrived);
            if (!ft.isEmpty()) {
                connection.createStatement().execute("DELETE FROM Crisis_Fire_truck WHERE crisis_id = " + _crisis_id + " AND fire_truck_name = '" + ft.get(0) + "'");
                return true;
            }
            ft = get_fire_trucks(Status.Blocked);
            if (!ft.isEmpty()) {
                connection.createStatement().execute("DELETE FROM Crisis_Fire_truck WHERE crisis_id = " + _crisis_id + " AND fire_truck_name = '" + ft.get(0) + "'");
                return true;
            }
        }
        return false;
    }

    public boolean recall_police_vehicle() throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.util.List<String> pv = get_police_vehicles(Status.Dispatched);
            if (!pv.isEmpty()) {
                connection.createStatement().execute("DELETE FROM Crisis_Police_vehicle WHERE crisis_id = " + _crisis_id + " AND police_vehicle_name = '" + pv.get(0) + "'");
                return true;
            }
            pv = get_police_vehicles(Status.Arrived);
            if (!pv.isEmpty()) {
                connection.createStatement().execute("DELETE FROM Crisis_Police_vehicle WHERE crisis_id = " + _crisis_id + " AND police_vehicle_name = '" + pv.get(0) + "'");
                return true;
            }
            pv = get_police_vehicles(Status.Blocked);
            if (!pv.isEmpty()) {
                connection.createStatement().execute("DELETE FROM Crisis_Police_vehicle WHERE crisis_id = " + _crisis_id + " AND police_vehicle_name = '" + pv.get(0) + "'");
                return true;
            }
        }
        return false;
    }

    public void record_timeout_reason(Long delay, String reason) {
        _timeout_log.add(new Timeout_log(new java.util.Date(), delay, reason));
    }

    public void set_number_of_fire_truck_required(Integer number_of_fire_truck_required) throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis SET fire_truck_number = " + String.valueOf(number_of_fire_truck_required) + " WHERE crisis_id = " + String.valueOf(_crisis_id));
        }
    }

    public void set_number_of_police_vehicle_required(Integer number_of_police_vehicle_required) throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            connection.createStatement().executeUpdate("UPDATE Crisis SET police_truck_number = " + String.valueOf(number_of_police_vehicle_required) + " WHERE crisis_id = " + String.valueOf(_crisis_id));
        }
    }

    /**
     * Invariants
     */
    public boolean FT_dispatched_equal_to_FT_required() throws java.sql.SQLException {
        return get_number_of_fire_truck_required() == get_fire_trucks(Status.Dispatched).size();
    }

    public boolean PV_dispatched_equal_to_PV_required() throws java.sql.SQLException {
        return get_number_of_police_vehicle_required() == get_police_vehicles(Status.Dispatched).size();
    }

    public boolean FT_arrived_greater_or_equal_to_FT_dispatched() throws java.sql.SQLException {
        return get_fire_trucks(Status.Arrived).size() >= get_fire_trucks(Status.Dispatched).size();
    }

    public boolean PV_arrived_greater_or_equal_to_PV_dispatched() throws java.sql.SQLException {
        return get_police_vehicles(Status.Arrived).size() >= get_police_vehicles(Status.Dispatched).size();
    }

    /**
     * Utilities
     */
    public java.util.List<String> get_fire_trucks() throws java.sql.SQLException {
        java.util.List<String> fire_trucks = new java.util.ArrayList<>();
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.sql.ResultSet rs = connection.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE, java.sql.ResultSet.CONCUR_READ_ONLY).executeQuery("SELECT * FROM Fire_truck");
            rs.beforeFirst();
            while (rs.next()) {
                fire_trucks.add(rs.getString("fire_truck_name"));
            }
        }
        return fire_trucks;
    }

    public java.util.List<String> get_fire_trucks(Status status) throws java.sql.SQLException {
        java.util.List<String> fire_trucks = new java.util.ArrayList<>();
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.sql.ResultSet rs = connection.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE, java.sql.ResultSet.CONCUR_READ_ONLY).executeQuery("SELECT * FROM Crisis_Fire_truck WHERE crisis_id = " + _crisis_id + " AND fire_truck_status = " + '\'' + status + '\'');
            rs.beforeFirst();
            while (rs.next()) {
                fire_trucks.add(rs.getString("fire_truck_name"));
            }
        }
        return fire_trucks;
    }

    public java.util.List<String> get_police_vehicles() throws java.sql.SQLException {
        java.util.List<String> police_vehicles = new java.util.ArrayList<>();
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.sql.ResultSet rs = connection.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE, java.sql.ResultSet.CONCUR_READ_ONLY).executeQuery("SELECT * FROM Police_vehicle");
            rs.beforeFirst();
            while (rs.next()) {
                police_vehicles.add(rs.getString("police_vehicle_name"));
            }
        }
        return police_vehicles;
    }

    public java.util.List<String> get_police_vehicles(Status status) throws java.sql.SQLException {
        java.util.List<String> police_vehicles = new java.util.ArrayList<>();
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.sql.ResultSet rs = connection.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE, java.sql.ResultSet.CONCUR_READ_ONLY).executeQuery("SELECT * FROM Crisis_Police_vehicle WHERE crisis_id = " + _crisis_id + " AND police_vehicle_status = " + '\'' + status + '\'');
            rs.beforeFirst();
            while (rs.next()) {
                police_vehicles.add(rs.getString("police_vehicle_name"));
            }
        }
        return police_vehicles;
    }

    public java.util.List<String> get_routes() throws java.sql.SQLException {
        java.util.List<String> routes = new java.util.ArrayList<>();
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            java.sql.ResultSet rs = connection.createStatement(java.sql.ResultSet.TYPE_SCROLL_INSENSITIVE, java.sql.ResultSet.CONCUR_READ_ONLY).executeQuery("SELECT * FROM Route");
            rs.beforeFirst();
            while (rs.next()) {
                routes.add(rs.getString("route_name"));
            }
        }
        return routes;
    }

    public int get_number_of_fire_truck_required() throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            //        java.sql.ResultSet rs = connection.createStatement().executeQuery("SELECT fire_truck_number FROM Crisis WHERE crisis_id = (SELECT MAX(crisis_id) FROM Crisis)");
            java.sql.ResultSet rs = connection.createStatement().executeQuery("SELECT fire_truck_number FROM Crisis WHERE crisis_id = " + _crisis_id);
            if (rs.next()) {
                return rs.getInt(1);
            }
        }
// Error:
        return -1;
    }

    public int get_number_of_police_vehicle_required() throws java.sql.SQLException {
        try (java.sql.Connection connection = java.sql.DriverManager.getConnection("jdbc:derby:BCMS_database")) {
            //        java.sql.ResultSet rs = connection.createStatement().executeQuery("SELECT police_truck_number FROM Crisis WHERE crisis_id = (SELECT MAX(crisis_id) FROM Crisis)");
            java.sql.ResultSet rs = connection.createStatement().executeQuery("SELECT police_truck_number FROM Crisis WHERE crisis_id = " + _crisis_id);
            if (rs.next()) {
                return rs.getInt(1);
            }
        }
// Error:
        return -1;
    }
}
