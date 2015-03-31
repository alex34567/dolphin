// Copyright 2013 Dolphin Emulator Project
// Licensed under GPLv2
// Refer to the license.txt file included.

#ifndef _EXIDEVICE_AMBASEBOARD_H
#define _EXIDEVICE_AMBASEBOARD_H

class CEXIAMBaseboard : public IEXIDevice
{
public:
	CEXIAMBaseboard();

	virtual void SetCS(int _iCS) override;
	virtual bool IsPresent() override;
	virtual bool IsInterruptSet() override;
	virtual void DoState(PointerWrap &p) override;

	~CEXIAMBaseboard();

private:
	virtual void TransferByte(u8& _uByte) override;
	int m_position;
	bool m_have_irq;
	u32 m_irq_timer;
	u32 m_irq_status;
	unsigned char m_command[4];
	unsigned short m_backoffset;
	File::IOFile *m_backup;
};

#endif
