#include "cSwivelCamera.h"

cSwivelCamera::cSwivelCamera(bool forward) {
	m_forward = forward;
}

void cSwivelCamera::Initialize() {

}

void cSwivelCamera::Execute() {
	if(m_forward) {
		CommandBase::s_turret->setSetpoint(TURRET_MIN_ENC);
	} else {
		CommandBase::s_turret->setSetpoint(TURRET_MAX_ENC);
	}
}

bool cSwivelCamera::IsFinished() { //Will run Execute() once and then kill the command
	return true;
}

void cSwivelCamera::End() {

}

void cSwivelCamera::Interrupted() {
	End();
}
