using System.Runtime.Serialization;
using Almostengr.AlmostengrWebsite.Domain.Common.Exceptions;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    internal class NwsObservationYesterDayCountZeroException : AlmostengrWebsiteException
    {
        public NwsObservationYesterDayCountZeroException()
        {
        }

        public NwsObservationYesterDayCountZeroException(string message) : base(message)
        {
        }

        public NwsObservationYesterDayCountZeroException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }

        public NwsObservationYesterDayCountZeroException(string? message, Exception? innerException) : base(message, innerException)
        {
        }
    }
}