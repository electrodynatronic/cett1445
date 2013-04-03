import eeml
import serial

# parameters
API_KEY = '8OxrDVNHIGsjJFb8jB-of7h2U9GHJYNFyCtJ60Mw_Hc'
#http://api.pachube.com/v2/feeds/11360.csv
API_URL = '/v2/feeds/11360.xml'


ss = serial.Serial('/dev/ttyUSB1', 9600, timeout=1)
#print ss.portstr 

ss.write('t')
#readings = ['0', '1', '2', '3', '4', '5', '6']
readings = ss.readline().strip().split(' ') # the readings are separated by spaces
print readings
ss.flush()
pac = eeml.Cosm(API_URL, API_KEY)
pac.update([eeml.Data(0, readings[1], unit=eeml.Fahrenheit()), eeml.Data(3, readings[0], unit=eeml.Bogus())])
pac.put()
