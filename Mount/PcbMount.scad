$fa = $preview ? 12 : 1;
$fs = $preview ?  2 : 0.15;

y_pot = 19.90 + 3.88 / 2;
x_pot = 58.96 + 3.88 / 2;
x_hole = 4.53 + 3.25 / 2;
y_hole = 23.65 + 3.25 / 2;
y_top = 59.85;
x_connector = 23.31 + 1.65 / 2;
y_connector = 22.30 + 1.65 / 2;

pcb_thickness = 1.60;
pc104_length = 21.32 - 8.49 + 0.5;
top_standoff_height = 5.00;
bottom_standoff_height = pc104_length - pcb_thickness - top_standoff_height;

pcb_notch_width = 12.12 - 0.5;
pcb_notch_height = 2.44;

pcb_stand_off_overhang_y = 2.00;
pcb_stand_off_overhang_z = 1.50;
pcb_stand_off_height = pcb_notch_height + pcb_stand_off_overhang_z;

module notch_stand_off() {
    difference() {
        translate([0, 0, -(pcb_thickness + pcb_stand_off_overhang_z)]) {
            thickness = pcb_stand_off_overhang_z + pcb_thickness + bottom_standoff_height;
            cube([pcb_notch_width, pcb_stand_off_height, thickness]);
        }
        translate([0, 0, -pcb_thickness]) {
            height = pcb_notch_height + pcb_stand_off_overhang_z;
            thickness = pcb_stand_off_overhang_z + pcb_thickness + bottom_standoff_height;
            cube([pcb_notch_width, pcb_notch_height, pcb_thickness + 0.1]);
        }
    }
}


standoff1_knurl_height = 5.00;
standoff1_knurl_diameter = 4.00;  // Use superclue.
standoff1_diameter = 6.00;
standoff1_offset_x = x_pot - x_hole;
standoff1_offset_y = y_hole - y_pot;

module standoff1() {
    difference() {
        cylinder(bottom_standoff_height, d = standoff1_diameter, true);
        cylinder(1.5 * standoff1_knurl_height, d = standoff1_knurl_diameter, true);
    }
}

standoff_pot_pcb_hole_diameter = 3.88 - 0.5;
standoff_pot_diameter = standoff1_diameter;

module standoff_pot() {
    union() {
        cylinder(bottom_standoff_height, d = standoff_pot_diameter, true);
        translate([0, 0, -pcb_thickness]) {
            cylinder(pcb_thickness, d = standoff_pot_pcb_hole_diameter, true);
        }
    }
}

pcb_stand_off1_offset_x = x_pot - (48.83 + 12.12);
pcb_stand_off1_offset_y = y_top - pcb_stand_off_height - y_pot;
pcb_stand_off2_offset_x = x_pot - (4.00 + 12.12);;
pcb_stand_off2_offset_y = pcb_stand_off1_offset_y;

module bottom_standoffs()
{
    union() {
        standoff_pot();
        translate([standoff1_offset_x, standoff1_offset_y, 0]) {
            standoff1();
        }
        translate([pcb_stand_off1_offset_x, pcb_stand_off1_offset_y, 0]) {
            notch_stand_off();
        }
        translate([pcb_stand_off2_offset_x, pcb_stand_off2_offset_y, 0]) {
            notch_stand_off();
        }
    }
}

module plate() {
    plate_width = 62.25;
    plate_height = 42.00;
    plate_thickness = 3.00;
    plate_radius = 2;
    plate_bar_size = 9.00;

    module plate() {
        difference() {
            cube([plate_width, plate_height, plate_thickness]);
            translate([plate_bar_size, plate_bar_size, 0]) {
                cube([plate_width - 2 * plate_bar_size, plate_height - 2 * plate_bar_size, plate_thickness]);
            }
        }
    }

    x = (standoff1_offset_x + standoff1_diameter / 2) - plate_width;
    y = pcb_stand_off1_offset_y + pcb_stand_off_height - plate_height;
    z = bottom_standoff_height - plate_thickness;
    translate([x, y, z]) {
        union() {
            plate();
        }
    }
}

connector_opening_width = 18.43 + 2.0;
connector_opening_height = 2.50 + 2.0;
connector_opening_offeset_x = x_pot - x_connector;
connector_opening_offeset_y = y_connector - y_pot;

module connector_opening() {
    translate([connector_opening_offeset_x, connector_opening_offeset_y, 0]) {
        cube([connector_opening_width, connector_opening_height, 100], center = true);
    }
}

module mount() {
    difference() {
        union() {
            bottom_standoffs();
            plate();
        }
        connector_opening();
    }
}

module top_standoff() {
    // m2 x 3
    top_standoff_diameter = 7.00;
    top_standoff_knurl_height = 3.05;
    top_standoff_knurl_diameter = 3.50;

    difference() {
        cylinder(top_standoff_height, d = top_standoff_diameter, true);
        translate([0, 0, top_standoff_height - 1.5 * top_standoff_knurl_height]) {
            cylinder(1.5 * top_standoff_knurl_height, d = top_standoff_knurl_diameter, true);
        }
    }
}


// top_standoff();

mount();