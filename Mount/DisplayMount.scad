window_width = 97.0;
window_height = 21.0;

display_width = 87.97 + 0.9;
display_height = 27.75 + 0.9;
display_offset = 3.26 - 2.53;

frame_extra = 5.0;
frame_width = window_width + 2 * frame_extra;
frame_height = 33.6;
frame_thickness = 3.54 - 1.00;

cable_width = 60.00 + 2.0;
cable_heigh = 3.55 - 1.98 + 0.5;

window_fitting_thickness = 0.8;

view_width = 77.12 + 0.2;
view_height = 33.55 - 5.31 - 8.86 + 0.2;
view_offset = 8.86 - 5.31;
view_overhang = 0.6;

cable_slot_width = 6.50;
cable_slot_height = 24.0;
cable_slot_thickness = 1.8;

notch_width = 69.00;
notch_height = 22.25;

module base() {
    difference() {
        cube(size = [frame_width, frame_height, frame_thickness]);
        x = (frame_width - display_width) / 2;
        y = (frame_height - display_height) / 2 + display_offset;
        translate([x, y, 0]) {
            cube(size = [display_width, display_height, frame_thickness]);
        }
    }
}

module cable_slot() {
    x = frame_width - cable_slot_width;
    y = (frame_height - cable_slot_height) / 2;
    translate([x, y, 0]) {
        cube(size = [cable_slot_width, cable_slot_height, cable_slot_thickness]);
    }
}

module window_fitting() {
    effective_window_width = window_width - 0.5;
    effective_window_height = window_height - 0.5;
    x = (frame_width - effective_window_width) / 2;
    y = (frame_height - effective_window_height) / 2 + view_offset / 2;
    translate([x, y, frame_thickness]) {
        difference() {
            cube(size = [effective_window_width, effective_window_height, window_fitting_thickness]);
            effective_width = display_width - 2 * view_overhang;
            x = (effective_window_width - effective_width) / 2;
            translate([x, 0, 0]) {
                cube(size = [effective_width, effective_window_height, window_fitting_thickness]);
            }
        }
    }
}

module notch() {
    translate([notch_height, 0, 0]) {
        nocth_height = (frame_height - display_height) / 2 + display_offset;
        cube(size = [notch_width, nocth_height, frame_height]);
    }
}

module mount() {
    union() {
        difference() {
            base();
            cable_slot();
            notch();
        }
        window_fitting();
    }
}

mount();

