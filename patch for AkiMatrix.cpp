void AkiMatrix::bitBlt16(uint8_t pos, const uint16_t *src)
{

	uint8_t vx, vy, i, j;
	uint8_t tmp;
	
	vx = 2 * pos;

	for(i=0; i<16; i++){		//row
	   tmp = (*src & 0xff00) >> 8;
       _vramBuffer[i][vx] = (tmp & 0x1) << 7 | \
       						(tmp & 0x2) << 5 | \
       						(tmp & 0x4) << 3 | \
       						(tmp & 0x8) << 1 | \
       						(tmp & 0x10) >> 1 | \
       						(tmp & 0x20) >> 3 | \
       						(tmp & 0x40) >> 5 | \
       						(tmp & 0x80) >> 7;
       
	   tmp = *src & 0xff;
       _vramBuffer[i][vx+1] = (tmp & 0x1) << 7 | \
       						(tmp & 0x2) << 5 | \
       						(tmp & 0x4) << 3 | \
       						(tmp & 0x8) << 1 | \
       						(tmp & 0x10) >> 1 | \
       						(tmp & 0x20) >> 3 | \
       						(tmp & 0x40) >> 5 | \
       						(tmp & 0x80) >> 7;
       src++;
	}
}