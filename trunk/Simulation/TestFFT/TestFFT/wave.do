onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix decimal /ffttestbench/uut/s_InWrAddr
add wave -noupdate /ffttestbench/s_tb_data_av
add wave -noupdate /ffttestbench/s_tb_data_in
add wave -noupdate /ffttestbench/s_tb_raddr
add wave -noupdate /ffttestbench/s_tb_rdata
add wave -noupdate /ffttestbench/s_tb_blockexp
add wave -noupdate /ffttestbench/s_tb_data_rdy
add wave -noupdate /ffttestbench/uut/inst_BatFFT/start
add wave -noupdate /ffttestbench/uut/inst_BatFFT/unload
add wave -noupdate /ffttestbench/uut/inst_BatFFT/fwd_inv
add wave -noupdate /ffttestbench/uut/inst_BatFFT/fwd_inv_we
add wave -noupdate /ffttestbench/uut/inst_BatFFT/rfd
add wave -noupdate /ffttestbench/uut/inst_BatFFT/busy
add wave -noupdate /ffttestbench/uut/inst_BatFFT/edone
add wave -noupdate /ffttestbench/uut/inst_BatFFT/done
add wave -noupdate /ffttestbench/uut/inst_BatFFT/dv
add wave -noupdate /ffttestbench/uut/inst_BatFFT/xn_re
add wave -noupdate /ffttestbench/uut/inst_BatFFT/xn_im
add wave -noupdate /ffttestbench/uut/inst_BatFFT/xn_index
add wave -noupdate /ffttestbench/uut/inst_BatFFT/xk_index
add wave -noupdate /ffttestbench/uut/inst_BatFFT/xk_re
add wave -noupdate /ffttestbench/uut/inst_BatFFT/xk_im
add wave -noupdate /ffttestbench/uut/inst_BatFFT/blk_exp
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {950269405 ps} 0}
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
WaveRestoreZoom {945618502 ps} {961199026 ps}
