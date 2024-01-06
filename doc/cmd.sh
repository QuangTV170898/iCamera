# sd card
mount /dev/mmcblk0p1 /media/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/media/iCamera/lib/

# transfer file use wget :)))
wget http://192.168.1.104:8000/iCamera -P /tmp
chmod +x iCamera
/tmp/iCamera

# wifi
## list all interface support
iwconfig

wlan0     IEEE 802.11bgn  ESSID:"NguoiTinh@12345"  
          Mode:Managed  Frequency:2.412 GHz  Access Point: 18:D0:71:94:01:93
          Bit Rate=1 Mb/s
          Retry long limit:7   RTS thr:off   Fragment thr:off
          Encryption key:off
          Power Management:on
          Link Quality=70/70  Signal level=-33 dBm
          Rx invalid nwid:0 Rx invalid crypt:0  Rx invalid frag:0
          Tx excessive retries:0  Invalid misc:0   Missed beacon:0

mon.p2p0  IEEE 802.11bgn  Mode:Monitor
          Retry  long limit:7   RTS thr:off   Fragment thr:off
          Power Management:on

p2p0      IEEE 802.11bgn  Mode:Master
          Retry  long limit:7   RTS thr:off   Fragment thr:off
          Power Management:on


## station mode 
killall -9 wpa_supplicant
killall -9 udhcpc
wpa_supplicant -c /configs/wpa_supplicant.conf -i wlan0 &
udhcpc -i wlan0 &

## access point mode
ifconfig p2p0 192.168.39.1
hostapd /configs/hostapd.conf -B
udhcpd -f /configs/udhcpd.conf &