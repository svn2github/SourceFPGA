onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /dctestbench/s_tb_reset
add wave -noupdate /dctestbench/s_tb_625
add wave -noupdate /dctestbench/s_tb_data_av_in
add wave -noupdate /dctestbench/s_tb_data_av_out
add wave -noupdate -format Analog-Step -height 74 -max 6573060.0 -min -6779390.0 /dctestbench/s_tb_R_data_in
add wave -noupdate /dctestbench/s_tb_L_data_in
add wave -noupdate -format Analog-Step -height 74 -max 1693030.0 -min -1750820.0 /dctestbench/s_tb_R_data_out
add wave -noupdate /dctestbench/s_tb_L_data_out
add wave -noupdate /dctestbench/s_tb_random
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1235710000 ps} 0}
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
WaveRestoreZoom {0 ps} {5049545213 ps}
