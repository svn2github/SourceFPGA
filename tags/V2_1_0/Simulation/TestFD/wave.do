onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /fdtestbench/s_tb_reset
add wave -noupdate -format Analog-Step -height 74 -max 6573055.0000000009 -min -6779393.0 /fdtestbench/s_tb_R_data_in
add wave -noupdate -format Analog-Step -height 74 -max 6604032.0 -min -6779648.0 /fdtestbench/s_tb_L_data_in
add wave -noupdate -format Analog-Step -height 74 -max 1033982.9999999998 -min -1657855.0 /fdtestbench/uut/s_ActValFilt_R
add wave -noupdate -format Analog-Step -height 74 -max 3590095.9999999995 -min -3556645.0 /fdtestbench/s_tb_R_data_out
add wave -noupdate -format Analog-Step -height 74 -max 3629475.0000000005 -min -3687959.0 /fdtestbench/s_tb_L_data_out
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1264510000 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits us
update
WaveRestoreZoom {0 ps} {6113079 ns}
