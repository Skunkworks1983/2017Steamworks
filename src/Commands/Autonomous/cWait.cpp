#include "cWait.h"

cWait::cWait(float timeout) {
	m_timeout = timeout;
}

void cWait::Initialize() {
	SetTimeout(m_timeout);
}

void cWait::Execute() {

}

bool cWait::IsFinished() {
	return IsTimedOut();
}

void cWait::End() {

}

void cWait::Interrupted() {
	End();
}
