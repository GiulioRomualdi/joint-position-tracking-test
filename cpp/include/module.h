/**
 * @file module.h
 * @authors Giulio Romualdi
 * @copyright Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 * @date 2020
 */

#ifndef MODULE_H
#define MODULE_H

// std
#include <memory>
#include <string>
#include <vector>

// YARP
#include <yarp/os/RFModule.h>

#include <BipedalLocomotion/ParametersHandler/IParametersHandler.h>
#include <BipedalLocomotion/Planners/QuinticSpline.h>
#include <BipedalLocomotion/RobotInterface/YarpRobotControl.h>
#include <BipedalLocomotion/RobotInterface/YarpSensorBridge.h>

class Module : public yarp::os::RFModule
{
    double m_dT; /**< RFModule period. */
    std::string m_robot; /**< Robot name. */

    Eigen::VectorXd m_currentJointPos;

    std::shared_ptr<yarp::dev::PolyDriver> m_robotDevice;

    BipedalLocomotion::RobotInterface::YarpRobotControl m_robotControl;
    BipedalLocomotion::RobotInterface::YarpSensorBridge m_sensorBridge;

    std::vector<double> m_setPoints;
    std::vector<double>::const_iterator m_currentSetPoint;

    BipedalLocomotion::Planners::QuinticSpline m_spline;
    std::vector<double> m_timeKnots;
    std::vector<Eigen::VectorXd> m_trajectoryKnots;

    double m_initTrajectoryTime;

    bool generateNewTrajectory();

    bool createPolydriver(
        std::shared_ptr<BipedalLocomotion::ParametersHandler::IParametersHandler> handler);

    bool initializeRobotControl(
        std::shared_ptr<BipedalLocomotion::ParametersHandler::IParametersHandler> handler);

    bool instantiateSensorBridge(
        std::shared_ptr<BipedalLocomotion::ParametersHandler::IParametersHandler> handler);

    std::vector<double> m_logJointPos;
    std::vector<double> m_logDesiredJointPos;

public:
    /**
     * Get the period of the RFModule.
     * @return the period of the module.
     */
    double getPeriod() override;

    /**
     * Main function of the RFModule.
     * @return true in case of success and false otherwise.
     */
    bool updateModule() override;

    /**
     * Configure the RFModule.
     * @param rf is the reference to a resource finder object
     * @return true in case of success and false otherwise.
     */
    bool configure(yarp::os::ResourceFinder& rf) override;

    /**
     * Close the RFModule.
     * @return true in case of success and false otherwise.
     */
    bool close() override;
};

#endif
