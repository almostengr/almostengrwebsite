using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    internal class NwsObservationYesterDayCountZeroException : Exception
    {
        public NwsObservationYesterDayCountZeroException()
        {
        }

        public NwsObservationYesterDayCountZeroException(string message) : base(message)
        {
        }
    }
}