import requests

url = 'http://ddnhehdam2vn0.cloudfront.net/features/bb2d84aa912e25a7fb5fc3c965e77849/256/18/206139/'
img_id = 125412

for img_id in range(125412, 125601):
	r = requests.get(url + str(img_id) + '.jpg')
	f = open('test' + str(img_id) + '.jpg', 'w')
	f.write(r.content)
print "Done."
f.close()
