// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/geofence/geofence.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "plugin_base.h"

namespace mavsdk {

class System;
class GeofenceImpl;

/**
 * @brief Enable setting a geofence.
 */
class Geofence : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto geofence = std::make_shared<Geofence>(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Geofence(System& system);

    /**
     * @brief Destructor (internal use only).
     */
    ~Geofence();

    /**
     * @brief Point type.
     */
    struct Point {
        double latitude_deg{}; /**< @brief Latitude in degrees (range: -90 to +90) */
        double longitude_deg{}; /**< @brief Longitude in degrees (range: -180 to +180) */
    };

    /**
     * @brief Equal operator to compare two `Geofence::Point` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Geofence::Point& lhs, const Geofence::Point& rhs);

    /**
     * @brief Stream operator to print information about a `Geofence::Point`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Geofence::Point const& point);

    /**
     * @brief Polygon type.
     */
    struct Polygon {
        /**
         * @brief Geofence polygon types.
         */
        enum class FenceType {
            Inclusion, /**< @brief Type representing an inclusion fence. */
            Exclusion, /**< @brief Type representing an exclusion fence. */
        };

        /**
         * @brief Stream operator to print information about a `Geofence::FenceType`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream&
        operator<<(std::ostream& str, Geofence::Polygon::FenceType const& fence_type);

        std::vector<Point> points{}; /**< @brief Points defining the polygon */
        FenceType fence_type{}; /**< @brief Fence type */
    };

    /**
     * @brief Equal operator to compare two `Geofence::Polygon` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Geofence::Polygon& lhs, const Geofence::Polygon& rhs);

    /**
     * @brief Stream operator to print information about a `Geofence::Polygon`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Geofence::Polygon const& polygon);

    /**
     * @brief Possible results returned for geofence requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        Error, /**< @brief Error. */
        TooManyGeofenceItems, /**< @brief Too many Polygon objects in the geofence. */
        Busy, /**< @brief Vehicle is busy. */
        Timeout, /**< @brief Request timed out. */
        InvalidArgument, /**< @brief Invalid argument. */
    };

    /**
     * @brief Stream operator to print information about a `Geofence::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Geofence::Result const& result);

    /**
     * @brief Callback type for asynchronous Geofence calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Upload a geofence.
     *
     * Polygons are uploaded to a drone. Once uploaded, the geofence will remain
     * on the drone even if a connection is lost.
     *
     * This function is non-blocking. See 'upload_geofence' for the blocking counterpart.
     */
    void upload_geofence_async(std::vector<Polygon> polygons, const ResultCallback callback);

    /**
     * @brief Upload a geofence.
     *
     * Polygons are uploaded to a drone. Once uploaded, the geofence will remain
     * on the drone even if a connection is lost.
     *
     * This function is blocking. See 'upload_geofence_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result upload_geofence(std::vector<Polygon> polygons) const;

    /**
     * @brief Copy constructor (object is not copyable).
     */
    Geofence(const Geofence&) = delete;

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Geofence& operator=(const Geofence&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<GeofenceImpl> _impl;
};

} // namespace mavsdk